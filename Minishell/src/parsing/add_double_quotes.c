#include "../head.h"

int	find_index_end_double_quotes(char *line, int index)
{
	if (line == NULL)
		return (-1);
	while (line[index] != '\0' && line[index] != '"')
		index++;
	if (line[index] == '\0')
		return (-1);
	return (index);
}

t_line	*create_node_for_double_quotes(t_all *all, t_line **head, int taille)
{
	t_line *new_node;

	new_node = malloc(sizeof(t_line));
	if (new_node == NULL)
	{
		free_all(all);
		free_list(head);
		exit (1);
	}
	new_node->valeur = malloc(sizeof(char) * (taille + 1));
	if (new_node->valeur == NULL)
	{
		free_all(all);
		free_list(head);
		free(new_node);
		exit (1);
	}
	new_node->quotes = DOUBLE_QUOTES;
	new_node->type = TOKEN_DOUBLE_QUOTES;
	new_node->command_type = PAS_COMMANDE;
	new_node->commande = NULL;
	new_node->commande_path = NULL;
  new_node->flag = NULL;
	new_node->argc = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = 0;
	return (new_node);
}

void	fill_node_double_quotes(char *line, t_line *node, int start, int end)
{
	int	i;

	i = 0;
	while (start != end)
	{
		node->valeur[i] = line[start];
		start++;
		i++;
	}
	node->valeur[i] = '\0';
}

void	add_double_quotes(t_all *all, t_line **head, int *index)
{
	int	i;
	t_line *node;
	int	indexe_start;
	int	indexe_end;

	i = *index + 1;
	indexe_start = i;
	indexe_end = find_index_end_double_quotes(all->line, i);
	if (indexe_end == -1)
	{
		free_all(all);
		free_list(head);
		printf("ERROR : double quotes non fermer\n");
		exit (1);
	}
	node = create_node_for_double_quotes(all, head, indexe_end - indexe_start);
	fill_node_double_quotes(all->line, node, indexe_start, indexe_end);
	add_node_to_head(head, node);
	*index = indexe_end + 1;
}
