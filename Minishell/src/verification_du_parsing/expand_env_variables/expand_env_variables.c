#include "../../head.h"
/*
int	find_if_exist()
{
	
}*/

int	create_env(char **env, char *str, int index)
{
	int	i;
	int	taille;

	taille = 0;
	index++;
	i = index;
	while (str[i] != '\0' && str[i] != '\'' && str[i] != '"' && str[i] != ' ' && str[i] != '$')
	{
		taille++;
		i++;
	}
	*env = malloc(sizeof(char) * (taille + 2));
	if (*env == NULL)
		return (1);
	i = index;
	(*env)[0] = '$';
	taille = 1;
	while (str[i] != '\0' && str[i] != '\'' && str[i] != '"' && str[i] != ' ' && str[i] != '$')
	{
		(*env)[taille] = str[i];
		i++;
		taille++;
	}
	(*env)[taille] = '\0';
	return (0);
}

int expand_env(t_line *node, t_all *all, char *str)
{
	int	i;
	int	error;
	char *env_str;

	error = 0;
	i = 0;
	env_str = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == '$' && str[i + 1] != '\0' && str[i + 1] != ' ' && str[i + 1] != '$')
		{
			error = create_env(&env_str, str, i);
			if (error == 1)
				return (1);
			error = find_if_exist(all->path, all->path_values, *env_str);
			printf("env var :%s\n", env_str);
			if (error == 1)
				return (1);
		}
		i++;
	}
	free(env_str);
	(void)all;
	(void)node;
	return (0);
}

int expand_env_variables(t_line **head, t_all *all)
{
  t_line *node;
  int error;

  error = 0;
  node = *head;
  while (node != NULL)
  {
    if (node->type == TOKEN_DOUBLE_QUOTES || node->type == TOKEN_WORD)
    {
      error = expand_env(node, all, node->valeur);
      if (error == 1)
        return (1);
    }
    node = node->next;
  }
  return (0);
}