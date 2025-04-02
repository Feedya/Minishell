#include "../../head.h"

void	create_char_commande_node(t_line *node, t_line **head, t_all *all)
{
	int	i;

	i = 0;
	while (node->valeur[i] != '\0' && node->valeur[i] != '-' && node->valeur[i] != ' ')
		i++;
	node->commande = malloc(sizeof(char) * (i + 1));
	if (node->commande == NULL)
	{
		free_all(all);
		free_list(head);
		exit (1);
	}
	i = 0;
	while (node->valeur[i] != '\0' && node->valeur[i] != '-' && node->valeur[i] != ' ')
	{
		node->commande[i] = node->valeur[i];
		i++;
	}
	node->commande[i] = '\0';
}