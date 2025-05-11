#include "../head.h"

t_line  *create_node_pipe(void)
{
  t_line *new_node;

  new_node = malloc(sizeof(t_line));
  if (new_node == NULL)
    return (NULL);
  new_node->valeur = malloc(sizeof(char) * (2));
  if (new_node->valeur == NULL)
    return (NULL);
  new_node->valeur[0] = '|';
  new_node->valeur[1] = '\0';
  new_node->type = TOKEN_PIPE;
  new_node->quotes = NONE;
  new_node->command_type = PAS_COMMANDE;
  new_node->fd = NULL;
  new_node->commande = NULL;
  new_node->commande_path = NULL;
  new_node->flag = NULL;
  new_node->argc = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
  new_node->build_in_type = NONE_FUNCT;
  new_node->index = 0;
  return (new_node);
}

void  add_pipe(t_all *all, t_line **head, int *index)
{
  t_line *node;
  
  node = create_node_pipe();
  if (node == NULL)
	{
		free_all(all);
		free_list(head);
		free(node);
		exit (1);
	}
	add_node_to_head(head, node);
  *index = *index + 1;
}