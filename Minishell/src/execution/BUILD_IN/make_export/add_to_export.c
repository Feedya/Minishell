#include "../../../head.h"

int create_first_export(t_all *all, char *valeur)
{
  int i;

  i = 0;
  all->export = malloc(sizeof(char *) * 2);
  if (all->export == NULL)
    return (1);
  i = ft_strlen(valeur);
  all->export[0] = malloc(sizeof(char) * (i + 1));
  if (all->export[0] == NULL)
    return (1);
  i = 0;
  while (valeur[i] != '\0')
  {
    all->export[0][i] = valeur[i];
    i++;
  }
  all->export[1] = NULL;
  return (0);
}

char	**malloc_copy_export(char **export, char *valeur)
{
	char	**copy_export;
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (export[i] != NULL)
		i++;
	copy_export = malloc(sizeof(char *) * (i + 2));
	if (copy_export == NULL)
		return (NULL);
	i = 0;
	while (export[i] != NULL)
	{
		c = 0;
		while (export[i][c] != '\0')
			c++;
		copy_export[i] = malloc(sizeof(char) * (c + 1));
		if (copy_export[i] == NULL)
		{
			free_double_char(copy_export);
			return (NULL);
		}
		while (export[i][c] != '\0')
		{
			copy_export[i][c] = export[i][c];
			c++;
		}
		copy_export[i][c] = '\0';
		i++;
	}
	c = 0;
	while (valeur[c] != '\0')
	{
		copy_export[i][c] = valeur[c];
		c++;
	}
	copy_export[i][c] = '\0';
	i++;
	copy_export[i] = NULL;
	return (0);
}

int	add_to_export(t_all *all, char *valeur)
{
	char **copy_export;

	copy_export = malloc_copy_export(all->export, valeur);
	free_double_char(all->export);
	all->export = copy_export;
	return (0);
}

int add_new_to_export(t_all *all, char *valeur)
{
  int error;

  error = 0;
  if (all->export == NULL)
  {
    error = create_first_export(all, valeur);
    if (error == 1)
      return (1);
  }
	else
	{
		error = add_to_export(all, valeur);
		if (error == 1)
			return (1);
	}
	return (0);
}
