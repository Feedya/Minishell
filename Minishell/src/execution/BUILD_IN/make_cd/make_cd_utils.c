#include "../../../head.h"

int	copy_old_in_new(char *new, char *second, char *first)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (first[i] != '\0')
	{
		new[c] = first[i];
		i++;
		c++;
	}
	i = 0;
	while (second[i] != '\0')
	{
		new[c] = second[i];
		i++;
		c++;
	}
	new[c] = '\0';
	return (0);
}

//mettre le nouveau oldpwd qui etait le pwd d avant
int	add_pwd_oldpwd(char *old, char **env, int mode)
{
	int	index;
	char	*new;
	int	taille;
	int	error;

	if (mode == 1)
		index = find_index_in_env(env, "OLDPWD");
	else if (mode == 0)
		index = find_index_in_env(env, "PWD");
	taille = ft_strlen(old) + 8;
	new = malloc(sizeof(char) * (taille));
	if (new == NULL)
		return (1);
	if (mode == 1)
		error = copy_old_in_new(new, old, "OLDPWD=");
	if (mode == 0)
		error = copy_old_in_new(new, old, "PWD=");
	if (error == 1)
		return (1);
	free(env[index]);
	env[index] = new;
	return (0);
}

int	find_index_in_env(char **env, char *str)
{
	int	index;
	int	c;

	index = 0;
	c = 0;
	while (env[index] != NULL)
	{
		c = 0;
		while (str[c] != '\0' && env[index][c] == str[c])
			c++;
		if (str[c] == '\0' && env[index][c] == '=')
			return (index);
		index++;
	}
	return (-1);
}

char	*take_env_from_index(t_all *all, int	index)
{
	char	*path;
	int	i;
	int	taille;

	taille = 0;
	i = 0;
	while (all->env[index][i] != '\0' && all->env[index][i] != '=')
		i++;
	i++;
	while (all->env[index][i] != '\0')
	{
		taille++;
		i++;
	}
	path = malloc(sizeof(char) * (taille + 1));
	if (path == NULL)
		return (NULL);
	i = 0;
	while (all->env[index][i] != '\0' && all->env[index][i] != '=')
		i++;
	i++;
	taille = 0;
	while (all->env[index][i] != '\0')
	{
		path[taille] = all->env[index][i];
		i++;
		taille++;
	}
	path[taille] = '\0';
	return (path);
}
