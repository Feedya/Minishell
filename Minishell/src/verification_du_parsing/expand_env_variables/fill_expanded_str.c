#include "../../head.h"

void	copy_env_in_str(t_all *all, char *expanded_str, int *index_env, char *env)
{
	int	i;
	int	index;
	int	c;

	c = *index_env;
	i = 0;
	index = fount_index_of_env(env, all);
	if (index == -1)
		return ;
	else
	{
		while (all->env[index][i] != '\0')
		{
			expanded_str[c] = all->env[index][i];
			i++;
			c++;
		}
		*index_env = c;
	}
}

int	fill_expanded_str(char *expanded_str, char *str, t_all *all)
{
	int	i;
	int	c;
	char	*env;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$' && str[i + 1] != '\0' && str[i + 1] != ' ')
		{
			env = take_name_of_env_from_str(str, i);
			if (env == NULL)
				return (1);
			copy_env_in_str(all, expanded_str, &c, env);
			free(env);
			i++;
			while (str[i] != '\0' && str[i] != ' ' && str[i] != '$')
				i++;
		}
		else
		{
			expanded_str[c] = str[i];
			i++;
			c++;
		}
	}
	expanded_str[c] = '\0';
	return (0);
}
 