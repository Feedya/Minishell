#include "../../../head.h"

char	*take_valeur_from_env(char *key, int index)
{
	char *valeur;
	int	i;
	int	c;

	i = 0;
	c = index;
	while (key[c] != '\0')
		c++;
	c = c - index;
	valeur = malloc(sizeof(char) * (c + 1));
	if (valeur == NULL)
		return (NULL);
	c = index;
	while (key[c] != '\0')
	{
		valeur[i] = key[c];
		i++;
		c++;
	}
	valeur[i] = '\0';
	return (valeur);
}

int	add_to_value_env(t_all *all, char *key)
{
	int index;
	char *valeur;
	char	**copy_env_valeur;


	index = 0;
	find_index_env_values(key, &index);
	valeur = take_valeur_from_env(key, index);
	if (valeur == NULL)
		return (1);
	copy_env_valeur = malloc_copy_env_export(all->path_values, valeur);
	if (copy_env_valeur == NULL)
		return (1);
	fill_copy_env(copy_env_valeur, all->path_values, valeur);
	free(valeur);
	free_double_char(all->path_values);
	all->path_values = copy_env_valeur;
	return (0);
}
