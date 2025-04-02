#include "../head.h"

void  remove_quotes_commande(t_line *node)
{
  int i;
  int c;

  c = 0;
  i = 0;
  while (node->valeur[i] != '\0')
  {
    if (node->valeur[i] != '"' && node->valeur[i] != '\'')
    {
      node->valeur[c] = node->valeur[i];
      i++;
      c++;
    }
    else
			i++;
  }
  node->valeur[c] = '\0';
}

void  remove_quotes_from_commande(t_line **head)
{
  t_line *node;

  node = *head;
  while (node != NULL)
  {
    if (node->type == TOKEN_COMMANDE)
    {
      remove_quotes_commande(node);
    }
    node = node->next;
  }
}
