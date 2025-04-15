#include "../head.h"

void	add_node_to_head(t_line **head, t_line *node)
{
	t_line *prev;

	if (head == NULL || node == NULL)
	{
		printf("erreur que normalement ne doit pas arriver dans :add_node_to_head: dans utils/utils_liste.c\n");
		return ;
	}
	if (*head == NULL)
	{
		*head = node;
		node->prev = NULL;
		return ;
	}
	prev = *head;
	while (prev->next != NULL)
		prev = prev->next;
	prev->next = node;
	node->prev = prev;
	node->next = NULL;
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
			printf("PATH :%s:\n", node->commande_path);
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

void	free_list(t_line **head)
{
	t_line *new_node;
	t_line *next;
	int	i;

	if (head == NULL || *head == NULL)
		return ;
	i = 0;
	new_node = *head;
	while (new_node != NULL)
	{
		next = new_node->next;
		if (new_node->flag != NULL)
		{
			free(new_node->flag);
			new_node->flag = NULL;
		}
		if (new_node->commande != NULL)
		{
			free(new_node->commande);
			new_node->commande = NULL;
		}
		if (new_node->argc != NULL)
		{
			i = 0;
			while (new_node->argc[i] != NULL)
			{
				free(new_node->argc[i]);
				new_node->argc[i] = NULL;
				i++;
			}
			free(new_node->argc);
			new_node->argc = NULL;
		}
		if (new_node->commande_path != NULL)
		{
			free(new_node->commande_path);
			new_node->commande_path = NULL;
		}
		if (new_node->valeur != NULL)
		{
			free(new_node->valeur);
			new_node->valeur = NULL;
		}
		free(new_node);
		new_node = NULL;
		new_node = next;	
	}
	free(head);
	head = NULL;
}
