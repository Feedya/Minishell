#include "../head.h"

int find_path_index(char **env)
{
  char dest[5];
  int index;
  int c;

	index = 0;
	c = 0;
  ft_strcpy("PATH", dest);
  while (env[index] != NULL)
  {
    c = 0;
    while (env[index][c] == dest[c])
      c++;
    if (ft_strncmp(env[index], dest, 5) == 0)
      return (index);
    index++;
  }
  return (-1);
}

int count_number_of_path(char **env, int index)
{
	int	i;
	int	counter;

  counter = 0;
  i = 0;
  while (env[index][i] != '\0')
	{
		if (env[index][i] == ':')
			counter++;
		i++;
	}
	counter++;
	return (counter);
}

void	malloc_small_parts_path_all(t_all *all, int index)
{
	int	i;
	int	taille;
	int	c;

	c = 0;
	i = 0;
	taille = 0;
	while (all->env[index][i] != '=')
		i++;
	i++;
	while (all->env[index][i] != '\0')
	{
		while (all->env[index][i] != '\0' && all->env[index][i] != ':')
		{
			i++;
			taille++;
		}
		if ((all->path[c] = malloc(sizeof(char) * (taille + 1))) == NULL)
		{
			free_all(all);
			exit (1);
		}
		c++;
		if (all->env[index][i] == ':')
			i++;
		taille = 0;
	}
}

void  malloc_path_all(t_all *all, int index)
{
  int taille;

  taille = count_number_of_path(all->env, index);
	all->path = malloc(sizeof(char *) * (taille + 1));
	if (all->path == NULL)
	{
		free_all(all);
		exit (1);
	}
	all->path[taille] = NULL;
	malloc_small_parts_path_all(all, index);
}

void	fill_path_in_all(t_all *all, int index)
{
	int	i;
	int	c;
	int	d;

	i = 0;
	c = 0;
	d = 0;
	while (all->env[index][i] != '/')
		i++;
	while (all->env[index][i] != '\0')
	{
		if (all->env[index][i] == ':')
		{
			all->path[c][d] = '\0';
			i++;
			c++;
			d = 0;
		}
		else
		{
			all->path[c][d] = all->env[index][i];
			d++;
			i++;
		}
	}
	all->path[c][d] = '\0';
}

void  copy_path(t_all *all)
{
  int path_index;

  if ((path_index = find_path_index(all->env)) == -1)
    free_all(all);
  malloc_path_all(all, path_index);
	fill_path_in_all(all, path_index);
}