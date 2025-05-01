#include "../head.h"

int check_pipe(t_line *node)
{
  if (node->next == NULL)
    return (1);
  if (node->next->type == TOKEN_PIPE)
    return (1);
  if (node->prev == NULL)
    return (1);
  return (0);
}

int verifier_pipe(t_line **head)
{
  t_line *node;

  node = *head;
  while (node != NULL)
  {
    if (node->type == TOKEN_PIPE)
    {
      if (check_pipe(node) == 1)
      {
        printf("pipe ends with null or another pipe\n");
        return (1);
      }
    }
    node = node->next;
  }
  return (0);
}