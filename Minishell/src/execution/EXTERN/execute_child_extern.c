#include "../../head.h"

/*
 int execve(const char *pathname, char *const _Nullable argv[],
                  char *const _Nullable envp[]);
*/
int execute_child_extern(t_shell_command *shell_node, t_all *all)
{
  char	*path;
  char	**argc;
	char	**env;
	int		error;

	argc = shell_node->command_info->argc;
	path = shell_node->command_info->commande_path;
	env = all->env;
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
	execve(path, argc, env);
	perror("ERREUR D ORDI : execve a bader (execute child)\n");
	exit (1);
}
