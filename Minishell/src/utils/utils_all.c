#include "../head.h"

t_all	*malloc_struct_all(void)
{
	t_all *all;

	all = malloc(sizeof(t_all));
	if (all == NULL)
		exit (1);
  all->commande = 0;
  all->line = NULL;
  all->path_values = NULL;
	all->env = NULL;
	all->path = NULL;
	return (all);
}

void  print_env(t_all *all)
{
  int i;

  i = 0;
  if (all->env != NULL)
  {
    printf("\nENV AVEC LES PATH\n");
		if (all->env[i] != NULL)
		{
    	while (all->env[i] != NULL)
    	{
      	printf("%s\n", all->env[i]);
      	i++;
    	}
		}
  }
  if (all->path_values != NULL)
  {
    printf("\nENV QUE VALEUR\n");
    i = 0;
    if (all->path_values[i] != NULL)
		{
    	while (all->path_values[i] != NULL)
    	{
      	printf("%s\n", all->path_values[i]);
      	i++;
    	}
		}
  }
}

void	free_all(t_all *all)
{
	int	i;

	i = 0;
	if (all != NULL)
	{
		if (all->env != NULL)
		{
			if (all->env[i] != NULL)
			{
				while (all->env[i] != NULL)
				{
					free(all->env[i]);
					all->env[i] = NULL;
					i++;
				}
			}
			free(all->env);
			all->env = NULL;
		}

		i  = 0;
		if (all->path != NULL)
		{
			if (all->path[i] != NULL)
			{
				while (all->path[i] != NULL)
				{
					free(all->path[i]);
					all->path[i] = NULL;
					i++;
				}
			}
			free(all->path);
			all->path = NULL;
		}

		if (all->path_values != NULL)
		{
			i = 0;
			if (all->path_values[i] != NULL)
			{
				while (all->path_values[i] != NULL)
				{
					free(all->path_values[i]);
					all->path_values[i] = NULL;
					i++;
				}
			}
			free(all->path_values);
			all->path_values = NULL;
		}
		if (all->line != NULL)
		{
			free(all->line);
			all->line = NULL;
		}
		free(all);
		all = NULL;
	}
}
