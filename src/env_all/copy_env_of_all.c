#include "../head.h"

int	malloc_small_parts_of_env_of_all(char **all_env, char **env)
{
	int	i;
	int	d;

	d = 0;
	i = 0;
	while (env[i] != NULL)
	{
		all_env[d] = malloc(sizeof(char) * (ft_strlen(env[i]) + 1));
		if (all_env[d] == NULL)
			return (1);
		d++;
		i++;
	}
	return (0);
}

void	malloc_env_of_all(t_all *all, char **env)
{
	int	big_size;

	big_size = 0;
	while (env[big_size] != NULL)
		big_size++;
	all->env = malloc(sizeof(char *) * (big_size + 1));
	if (all->env == NULL)
	{
		free(all);
		exit (1);
	}
  all->env[big_size] = NULL;
	if (malloc_small_parts_of_env_of_all(all->env, env) == 1)
	{
		printf("probleme malloc malloc small parts of env of all\n");
		free_all(all);
	}
}

void  fill_env_of_all(char **all_env, char **env)
{
  int i;

  i = 0;
  while (env[i] != NULL)
  {
		ft_strcpy(env[i], all_env[i]);
    i++;
  }
}

void	copy_env_in_all(t_all *all, char **env)
{
	malloc_env_of_all(all, env);
	fill_env_of_all(all->env, env);
}
