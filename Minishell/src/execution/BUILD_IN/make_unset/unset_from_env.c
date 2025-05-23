#include "../../../head.h"

int find_index_of_unset(char **env, char *str)
{
  int	i;
	int	c;

	i = 0;
	c = 0;
	while (env[i] != NULL)
	{
		c = 0;
		while (env[i][c] == str[c] && str[c] != '\0' && env[i][c] != '\0')
			c++;
		if (str[c] == '\0' && env[i][c] == '=')
			return (i);
		i++;
	}
	return (-1);
}

char	**malloc_env_without_var(char **env, int index)
{
	char	**copy_env;
	int	i;
	int	c;
	int	d;

	d = 0;
	i = 0;
	c = 0;
	while (env[i] != NULL)
		i++;
	i--;
	copy_env = malloc(sizeof(char *) * (i + 1));
	if (copy_env == NULL)
		return (NULL);
	i = 0;
	while (env[i] != NULL)
	{
		if (i == index)
			i++;
		else
		{
			c = 0;
			while (env[i][c] != '\0')
				c++;
			copy_env[d] = malloc(sizeof(char) * (c + 1));
			if (copy_env[d] == NULL)
			{
				free_double_char(copy_env);
				return (NULL);
			}
			d++;
			i++;		
		}
	}
	return (env);
}

void	fill_copy_env_without_var(char **env, char **copy_env, int index)
{
	
}

int unset_from_env(char **env, char *str)
{
  int index;
  char **env_copy;

  index = find_index_of_unset(env, str);
	if (index == -1)
		return (0);
	char **copy_env = malloc_env_without_var(env, index);
	if (copy_env == NULL)
		return (1);
	fill_copy_env_without_var(env, copy_env, index);
}