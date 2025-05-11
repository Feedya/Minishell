#include "../../head.h"

void make_child_build_in(t_shell_command *shell_node)
{
  e_build_in_type type;

  type = shell_node->command_info->build_in_type;
  if (type == ECHO_BUILD_IN)
  {
    make_build_in_echo(shell_node);
  }
  else if (type == CD_BUILD_IN)
  {
    make_build_in_cd(shell_node);
  }
  else if (type == PWD_BUILD_IN)
  else if (type == EXPORT_BUILD_IN)
  else if (type == UNSET_BUILD_IN)
  else if (type == ENV_BUILD_IN)
  else if (type == EXIT_BUILD_IN)*/
  exit (1);
}

int make_build_in_command(t_shell_command *shell_node, t_all *all)
{
  pid_t pid;

  pid = fork();
  if (pid == -1)
    return (1);
  if (pid == 0)//ENFANT
  {
    make_child_build_in(shell_node);
  }
  (void)all;
  return (0);//PARENT
}
