#include "../head.h"

void  free_shell_cmd(t_shell_command **head)
{
  t_shell_command *node;
  t_shell_command *next;

  if (*head != NULL)
    node = *head;
  while (node != NULL)
  {
    next = node->next;
    node->prev = NULL;
    node->next = NULL;
    node->command_info = NULL;
    free(node);
    node = NULL;
    node = next;
  }
  if (head != NULL)
  {
    free(head);
    head = NULL;
  }
}

t_shell_command ** malloc_head_shell_cmd(void)
{
	t_shell_command  **head;

	head = malloc(sizeof(t_shell_command *) * (1));
	if (head == NULL)
		return (NULL);
  *head = NULL;
	return (head);
}

t_shell_command	*create_shell_cmd_node(void)
{
	t_shell_command *node;

	node = malloc(sizeof(t_shell_command) * 1);
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->command_info = NULL;
	node->stdout = 0;
	node->stdin = 0;
	node->error_indicator = 0;
	return (node);
}

void  put_node_to_liste_shell_cmd(t_shell_command **head, t_shell_command *node)
{
  t_shell_command *prev;

  if (*head == NULL)
    *head = node;
  else
  {
    prev = *head;
    while (prev->next != NULL)
      prev = prev->next;
    prev->next = node;
    node->prev = prev;
  }
}
