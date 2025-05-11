#include "../head.h"

int	make_pipe(t_shell_command **shell_head)
{
	t_shell_command *shell_node;
	int	pipe_fd[2];

	shell_node = *shell_head;
	while (shell_node != NULL && shell_node->next != NULL)
	{
		if (pipe(pipe_fd) == -1)
		{
			perror("ERREUR DE CREATION DU PIPE : src/stick_stdin_stdout/stick_stdin_stdout.c\nfonction : make_pipe\n");
			return (1);
		}
		shell_node->stdout = pipe_fd[1];
		shell_node->next->stdin = pipe_fd[0];
		shell_node = shell_node->next;
	}
	return (0);
}
