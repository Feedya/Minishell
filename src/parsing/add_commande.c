#include "../head.h"

int	find_flag(char *line, int index)
{
	int	i;

	i = index;
	while (line[i] == ' ')
		i++;
	if (line[i] == '-')
	{
		while (1)
		{
			while (line[i] != ' ' && line[i] != '\0')
				i++;
			while (line[i] == ' ')
				i++;
			if (line[i] == '-')
				continue ;
			else
				break;
		}
	}
	return (i);
}

void	add_commande(int *index, t_all *all, t_line **head)
{
	int	i;
	t_line *new_node;
	char *line;

	i = *index;
	line = all->line;
	all->commande = 1;
	new_node = malloc(sizeof(t_line));
	if (new_node == NULL)
	{
		free_all(all);
		free_list(head);
		exit (1);
	}
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	i = find_flag(line, i);
	new_node->valeur = malloc(sizeof(char) * (i + 1));
	if (new_node->valeur == NULL)
	{
		free(new_node);
		free_list(head);
		free_all(all);
		exit (1);
	}
	ft_strncpy(line, new_node->valeur, 0, i);
	new_node->type = TOKEN_COMMANDE;
	new_node->quotes = NONE;
	new_node->next = NULL;
	new_node->prev = NULL;
	*head = new_node;
	*index = i;
}
