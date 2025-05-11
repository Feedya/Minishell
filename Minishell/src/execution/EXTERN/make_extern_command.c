#include "../../head.h"


int make_extern_command(t_shell_command *shell_node, t_all *all)
{
  pid_t pid;

  pid = fork();
  if (pid == -1)
    return (1);
  if (pid == 0)//ENFANT
  {
    execute_child_extern(shell_node, all);
  }
	//PARENT
	return (0);
}
