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

	argc = shell_node->command_info->argc;
	path = shell_node->command_info->commande_path;
	env = all->env;
	if (make_dup(shell_node) == 1)
		return (1);
	execve(path, argc, env);
	perror("ERREUR D ORDI : execve a bader (execute child)\n");
	exit (1);
}
