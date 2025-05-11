#include "../head.h"

/*(echo with option -n
◦ cd with only a relative or absolute path
◦ pwd with no options
◦ export with no options
◦ unset with no options
◦ env with no options or arguments
◦ exit with no option)*/

int	ft_comparer(char *str, char *str2) // renvoie 1 si faux et 0 si juste
{
	int	i;

	i = 0;
	while (str2[i] != '\0' && str[i] != '\0' && str[i] == str2[i])
		i++;
	if (str[i] == '\0')
		return (0);
	if (str2[i] == '\0')
		return (0);
	return (1);

}

int	see_if_build_in(t_line *node)
{
	if (ft_comparer(node->commande, "echo") == 0)
	{
		node->build_in_type = ECHO_BUILD_IN;
		return (0);
	}
	if (ft_comparer(node->commande, "cd") == 0)
	{
		node->build_in_type = CD_BUILD_IN;
		return (0);
	}
	if (ft_comparer(node->commande, "pwd") == 0)
	{
		node->build_in_type = PWD_BUILD_IN;
		return (0);
	}
	if (ft_comparer(node->commande, "export") == 0)
	{
		node->build_in_type = EXPORT_BUILD_IN;
		return (0);
	}
	if (ft_comparer(node->commande, "env") == 0)
	{
		node->build_in_type = ENV_BUILD_IN;
		return (0);
	}
	if (ft_comparer(node->commande, "unset") == 0)
	{
		node->build_in_type = UNSET_BUILD_IN;
		return (0);
	}
	if (ft_comparer(node->commande, "exit") == 0)
	{
		node->build_in_type = EXIT_BUILD_IN;
		return (0);
	}
	return (1);
}

int check_if_exist(char *path_complet, t_line *node)
{
    if (access(path_complet, F_OK) == 0 && access(path_complet, X_OK) == 0)//F_OK si existe et F_OX si executable
    {
			node->commande_path = path_complet;
			return (0);
		}
		return (1);
}

int	see_if_extern(char *commande, char **path, t_line *node)
{
	int	i;
	char *path_complet;

	i = 0;
	while (path[i] != NULL)
	{
		path_complet = malloc(sizeof(char) * (ft_strlen(path[i]) + ft_strlen(commande) + 2));
		if (path_complet == NULL)
			return (0);
		ft_strcpy(path[i], path_complet);
		ft_strcat(path_complet, "/");
		ft_strcat(path_complet, commande);
		if (check_if_exist(path_complet, node) == 0)
		{
			node->index = i;
			return (0);
		}
		free(path_complet);
		path_complet = NULL;
		i++;
	}
	return (1);
}

int	see_if_build_or_extern(t_line *node, t_all *all)
{
	int	build_in;
	int	extern_func;

	build_in = see_if_build_in(node);
	if (build_in == 0)
	{
		node->command_type = BUILD_IN;
		return (0);
	}
	else if (build_in == 1)
	{
		extern_func = see_if_extern(node->commande, all->path, node);
		if (extern_func == 0)
		{
			node->command_type = EXTERN;
			return (0);
		}
	}
	printf("%s: command not found\n", node->commande);
	return (1);
}

int verifier_commande(t_line **head, t_all *all)
{
	t_line *node;

	node = *head;
	while (node != NULL)
	{
		if (node->type == TOKEN_COMMANDE)
		{
			if (see_if_build_or_extern(node, all) == 1)
				return (1);
		}
		node = node->next;
	}
	return (0);
}
