#include "../head.h"

int	make_dup(t_shell_command *shell_node)
{
	int	error;

	if (shell_node->stdin != STDIN_FILENO)
	{
		error = dup2(shell_node->stdin, STDIN_FILENO);
		if (error < 0)
			return (1);
		close(shell_node->stdin);
	}
	if (shell_node->stdout != STDOUT_FILENO)
	{
		error = dup2(shell_node->stdout, STDOUT_FILENO);
		if (error < 0)
			return (1);
		close(shell_node->stdout);
	}
	return (0);
}
