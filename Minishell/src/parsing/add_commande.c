#include "../head.h"

//dans cette fonction on va renvoyer le fin des flags
//pwd  -lasd    asdads
int find_end_flag_command(char *line, int index)
{
  int index_fin;

  index_fin = index;
  while (1)
  {
    if (line[index] == '-')
    {
      while (line[index] != '\0' && line[index] != ' ' && line[index] != '>' && line[index] != '<')
        index++;
      index_fin = index;
    }
    while (line[index] == ' ')
      index++;
    if (line[index] != '-')
      break;
  }
  return (index_fin);
}

int	find_end_command(char *line, int index)
{
  //ls"ds"|pwd
  int index_fin;
  if (line[index] == '|')
    return (-1);
  
  // on saut les espaces ou les charactere tant qu on tombe pas sur un de ces charactere
  while (line[index] != '\0' && line[index] != ' ' && line[index] != '|' && line[index] != '>' && line[index] != '<')
    index++;
  index_fin = index;
  //on saut les espaces qui sont apres les charactere si il y a
  while (line[index] == ' ')
    index++;
  //cette boucle est pour sauter tout les flags de la commande
  if (line[index] == '-' && line[index] != '\0' && line[index] != ' ')
    index_fin = find_end_flag_command(line, index);
  return (index_fin);
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
  while (all->line[start] == ' ')
    start++;
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
  //fill_flag_and_commande(node, all, head); // on va remplir les varibles speciale pour 
  add_node_to_head(head, node);
  *index = end;
  all->commande = 1;
  //add_node_to_head(head, new_node);
}
