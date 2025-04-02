#include "../head.h"

int find_end(char *line, int i)
{
  while (line[i] != '\0' && line[i] != ' ' && line[i] != '>' && line[i] != '<' && line[i] != '|')
    i++;
  return (i);
}

t_line  *create_node_word(int taille)
{
  t_line  *new_node;

  new_node = malloc(sizeof(t_line));
  if (new_node == NULL)
    return (NULL);
  new_node->valeur = malloc(sizeof(char) * (taille + 1));
  if (new_node->valeur == NULL)
    return (NULL);
  new_node->quotes = NONE;
  new_node->type = TOKEN_WORD;
  new_node->command_type = PAS_COMMANDE;
  new_node->commande = NULL;
  new_node->flag = NULL;
  new_node->argc = NULL;
  new_node->next = NULL;
  new_node->prev = NULL;
  new_node->index = 0;
  return (new_node);
}

void  fill_word_node(char *line, t_line *node, int start, int end)
{
  int i;

  i = 0;
  while (start != end)
  {
    node->valeur[i] = line[start];
    start++;
    i++;
  }
  node->valeur[i] = '\0';
}

void  add_word(t_all *all, t_line **head, int *index)
{
  t_line *node;
  int start;
  int end;

  start = *index;
  end = find_end(all->line, start);
  node = create_node_word(end - start);
  if (node == NULL)
  {
    free_all(all);
    free_list(head);
    free(node);
    exit (1);
  }
  fill_word_node(all->line, node, start, end);
  add_node_to_head(head, node);
  *index = end;
}
