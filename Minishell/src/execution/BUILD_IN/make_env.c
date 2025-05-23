#include "../../head.h"

void  make_env(t_all *all, t_shell_command *shell_node)
{
  int i;

  make_dup(shell_node);
  i = 0;
  while (all->env[i] != NULL)
  {
    printf("%s\n", all->env[i]);
    i++;
  }
}
