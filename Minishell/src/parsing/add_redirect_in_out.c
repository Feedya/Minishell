#include "../head.h"

t_line  *create_node_in_out(char c)
{
  t_line *new_node;

  new_node = malloc(sizeof(t_line));
  if (new_node == NULL)
    return (NULL);
  new_node->valeur = malloc(sizeof(char) * (2));
  if (new_node->valeur == NULL)
    return (NULL);
  new_node->type = TOKEN_REDIRECT_IN;
  new_node->valeur[0] = '<';
  if (c == '>')
  {
    new_node->valeur[0] = '>';
    new_node->type = TOKEN_REDIRECT_OUT;
  }
  new_node->valeur[1] = '\0';
  new_node->quotes = NONE;
  new_node->command_type = PAS_COMMANDE;
  new_node->commande = NULL;
  new_node->flag = NULL;
  new_node->argc = NULL;
  new_node->next = NULL;
  new_node->prev = NULL;
  new_node->index = 0;
  return (new_node);
}

void  add_redirect_in_out(t_all *all, t_line **head, int *index)
{
  int i;
  t_line *node;

  i = *index;
  node = create_node_in_out(all->line[i]);
  if (node == NULL)
  {
    free_all(all);
    free_list(head);
    free(node);
    exit (1);
  }
  add_node_to_head(head, node);
  *index = i + 1;
}