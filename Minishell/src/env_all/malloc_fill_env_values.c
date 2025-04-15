#include "../head.h"

void	find_index_env_values(char *env, int *index)
{
	int	i;

	i = 0;
	while (env[i] != '\0')
	{
		if (env[i] == '=')
		{
			i++;
			*index = i;
			return ;
		}
		i++;
	}
	*index = -1;
}

int	malloc_and_fill_env_values(char *env, int index, char **remplir)
{
	int	temp_index;
	int	taille;

	if (env == NULL || index < 0)
		return (1);
	taille = 0;
	//index++;
	temp_index = index;
	while (env[index] != '\0')
	{
		index++;
		taille++;
	}
	*remplir = malloc(sizeof(char) * (taille + 1));
	if (*remplir == NULL)
		return (1);
	taille = 0;
	while (env[temp_index] != '\0')
	{
		(*remplir)[taille] = env[temp_index];
		temp_index++;
		taille++;
	}
	(*remplir)[taille] = '\0';
	return (0);
}

int	malloc_small_parts_env_all(char **path_values, char **env)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (env[i] != NULL)
	{
		index = 0;
		find_index_env_values(env[i], &index); // cette fociton va trouver l index apres le =
		if (index == -1)
		{
			printf("ERREUR : env_all/copy_env_of_all.c\nOn a pas reussis a trouver le = dans le path a la ligne %d l char **env est faux\n", i);
			return (1);
		}
		if (malloc_and_fill_env_values(env[i], index, &path_values[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	malloc_env_values(t_all *all, char **env, int big_size)
{
	int	error;
	error = 0;
	all->path_values = malloc(sizeof(char *) * (big_size + 1));//big size est bonne
	if (all->path_values == NULL)
	{
		free_all(all);
		exit (1);
	}
	all->path_values[big_size] = NULL;
	error = malloc_small_parts_env_all(all->path_values, env);
	if (error == 1)
	{
		free_all(all);
		exit (1);
	}
}
