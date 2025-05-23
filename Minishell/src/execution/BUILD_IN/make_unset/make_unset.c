#include "../../../head.h"

int	unset_all(char *str, t_all *all)
{
	int	error;

	error = unset_from_env(all->env, str);
	if (error == 1)
		return (1);
}

int make_unset(t_shell_command *shell_node, t_all *all)
{
  char **argc;
	int	i;
	int	error;

  if (shell_node->command_info->next == NULL)
    return (0);
	i = 0;
  argc = shell_node->command_info->argc;
  while (argc[i] != NULL)//on saute dans les atrguments
	{
		error = unset_all(argc[i], all);
		if (error == 1)
			return (1);
	}
}