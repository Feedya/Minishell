#include "../../head.h"

void make_child_build_in(t_shell_command *shell_node, t_all *all)
{
  e_build_in_type type;

  type = shell_node->command_info->build_in_type;
  if (type == ECHO_BUILD_IN)
  {
    make_build_in_echo(shell_node);
  }
  else if (type == PWD_BUILD_IN)
    make_pwd(shell_node);
  else if (type == ENV_BUILD_IN)
    make_env(all, shell_node);
  exit (1);
}

int make_build_in_command(t_shell_command *shell_node, t_all *all)
{
  pid_t pid;
  int error;

  error = 0;
  if (shell_node->command_info->build_in_type == CD_BUILD_IN)
  {
		error = make_cd(shell_node, all);
    if (error == 1)
      return (1);
  }
  else if (shell_node->command_info->build_in_type == EXIT_BUILD_IN)
    return (-1);
  else if (shell_node->command_info->build_in_type == EXPORT_BUILD_IN)
  {
    error = make_export(shell_node, all);
    if (error == 1)
      return (1);
  }
  else if (shell_node->command_info->build_in_type == UNSET_BUILD_IN)
  {
    error = make_unset(shell_node, all);
    if (error == 1)
      return (1);
  }
  else
  {
    pid = fork();
    if (pid == -1)
      return (1);
    if (pid == 0)//ENFANT
    {
      make_child_build_in(shell_node, all);
    }
  }
  return (0);//PARENT
}
