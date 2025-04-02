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
	int	c;

	c = 0;
	node = *head;
	while (node != NULL)
	{
		c = 0;
		printf("%d :%s:\n", node->type, node->valeur);
		if (node->type == TOKEN_COMMANDE)
		{
			if (node->argc != NULL)
			{
				while (node->argc[c] != NULL)
				{
					printf(" ARGC : :%s:\n", node->argc[c]);
					c++;
				}
			}
			printf("TYPE : %d\n", node->type);
			printf("COMMANDE TYPE : %d\n", node->command_type);
			printf("COMMANDE : :%s:\n", node->commande);
			printf("FLAG : :%s:\n", node->flag);
		}
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
