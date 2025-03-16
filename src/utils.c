#include "head.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

t_all	*malloc_struct_all(void)
{
	t_all *all;

	all = malloc(sizeof(t_all));
	if (all == NULL)
		exit (1);
	all->env = NULL;
	all->path = NULL;
	return (all);
}

void	ft_strcpy(char *str, char *dest)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_strncmp(char *avec_quoi, char *comparer, int nbr)
{
	int	i;

	i = 0;
	while (avec_quoi[i] != '\0' && avec_quoi[i] == comparer[i] && i != nbr)
		i++;
	if (comparer[i] == '\0')
		return (0);
	return (1);
}

void	ft_strncpy(char *str, char *dest, int index, int taille)
{
	int	i;

	i = 0;
	while (i != taille && str[index] != '\0')
	{
		dest[i] = str[index];
		i++;
		index++;
	}
	dest[i] = '\0';
}