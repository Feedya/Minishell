#include "../head.h"

t_line  *create_node_append_heredoc(char c)
{
  t_line *new_node;

  new_node = malloc(sizeof(t_line));
  if (new_node == NULL)
    return (NULL);
  new_node->valeur = malloc(sizeof(char) * (3));
  if (new_node->valeur == NULL)
    return (NULL);
  new_node->valeur[0] = '<';
  new_node->valeur[1] = '<';
	new_node->type = TOKEN_HEREDOC;
  if (c == '>')
  {
    new_node->valeur[0] = '>';
    new_node->valeur[1] = '>';
    new_node->type = TOKEN_APPEND;
  }
  new_node->valeur[2] = '\0';
  new_node->quotes = NONE;
  new_node->commande = NULL;
  new_node->flag = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void  add_append_heredoc(t_all *all, t_line **head, int *index)
{
  int i;
  t_line *node;

  i = *index;
  node = create_node_append_heredoc(all->line[i]);
  if (node == NULL)
  {
    free_all(all);
    free_list(head);
    free(node);
    exit (1);
  }
	add_node_to_head(head, node);
  *index = *index + 2;
}
