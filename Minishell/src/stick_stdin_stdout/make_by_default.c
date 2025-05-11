#include "../head.h"

void	make_by_default(t_shell_command **head)
{
	t_shell_command *node;

	node = *head;
	while (node != NULL)
	{
		node->stdin = STDIN_FILENO;
		node->stdout = STDOUT_FILENO;
		node = node->next;
	}
}

