#include "../head.h"

int	find_end_command(char *line, int index)
{
  int start_flag;

  while (line[index] != '\0' && line[index] != ' ' && line[index] != '|' && line[index] != '>' && line[index] != '<')
    index++;
  while (line[index] == ' ')
    index++;
  while (1)
  {
    if (line[index] == '-')
    {
			start_flag = index;
      while (line[index] != '\0' && line[index] != ' ' && line[index] != '|' && line[index] != '>' && line[index] != '<')
        index++;
			if (start_flag + 1 == index)
        return (-1);
			while (line[index] == ' ')
        index++;
		}
    else
		  break;
  }
	return (index);
}

t_line  *create_node_commande(int taille)
{
  t_line *new_node;

  new_node = malloc(sizeof(t_line));
  if (new_node == NULL)
    return (NULL);
  new_node->valeur = malloc(sizeof(char) * (taille + 1));
  if (new_node->valeur == NULL)
    return (NULL);
  new_node->quotes = NONE;
  new_node->type = TOKEN_COMMANDE;
  new_node->commande = NULL;
  new_node->flag = NULL;
  new_node->next = NULL;
  new_node->prev = NULL;
  return (new_node);
}

void  fill_node_commande(t_line *node, char *line, int start, int end)
{
  int i;

  i = 0;
  while (start != end)
  {
    node->valeur[i] = line[start];
    i++;
    start++;
  }
  node->valeur[i] = '\0';
}

void	add_commande(int *index, t_all *all, t_line **head)
{
  int start;
  int end;
  t_line *node;

  start = *index;
  end = find_end_command(all->line, start);
  if (end == -1)
  {
    free_all(all);
    free_list(head);
    printf("ERROR : un flags pour une commande n est pas bien ecris\n");
    exit (1);
  }
  node = create_node_commande(end - start);
  if (node == NULL)
  {
    free_all(all);
    free_list(head);
    free(node);
    exit (1);
  }
  fill_node_commande(node, all->line, start, end);
  fill_node_commande_flag_and_commade(node, all);
  add_node_to_head(head, node);
  *index = end;
  all->commande = 1;
  //add_node_to_head(head, new_node);
}