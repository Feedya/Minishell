#include "../head.h"

void	add_node_to_head(t_line **head, t_line *node)
{
	t_line *prev;

	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	prev = *head;
	while (prev->next != NULL)
		prev = prev->next;
	prev->next = node;
	node->prev = prev;
}

void	print_list(t_line **head)
{
	t_line *node;

	node = *head;
	while (node != NULL)
	{
		printf("%d : ", node->type);
		printf("%s\n", node->valeur);
		node = node->next;
	}
}

void	printf_liste_a_lenvers(t_line **head)
{
	t_line *node;
	node = *head;
	while (node->next != NULL)
		node = node->next;
	while (node->prev != NULL)
	{
		printf("%s\n", node->valeur);
		node = node->prev;
	}
	printf("%s\n", node->valeur);
}
