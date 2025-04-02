#include "../head.h"

int count_number_of_commands(t_line **head)
{
  t_line *node;
  int counter;

  node = *head;
  counter = 0;
  while (node != NULL)
  {
    if (node->command_type != PAS_COMMANDE)
      counter++;
    node = node->next;
  }
  return (counter);
}

void  execution(t_line **head, t_all *all)
{
  t_line *node;
  int number_of_commande;

  number_of_commande = count_number_of_commands(head);

  if (number_of_commande == 1)
  {
    one_command(head);
  }
  else if (number_of_commande > 0)
  {
    multiple_command(head, number_of_commande);
  }
}