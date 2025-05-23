#include "../../../head.h"

int	check_egale(t_shell_command *shell_node)
{
	char *valeur;
	int	i;

	i = 0;
	valeur = shell_node->command_info->next->valeur;
	while (valeur[i] != '\0')
	{
		if (valeur[i] == '=' && valeur[i + 1] == '\0')
			return (2);
		if (valeur[i] == '=' && valeur[i + 1] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int	add_val_export(t_shell_command *shell_node, t_all *all)
{
	int	error;
	char	*valeur;

	error = 0;
	valeur = shell_node->command_info->next->valeur;
	if (check_egale(shell_node) == 2)
		return (2);
	if (check_egale(shell_node) == 1)
	{
		error = add_to_env(shell_node, all, valeur);
		if (error == 1)
			return (1);
		error = add_to_value_env(all, valeur);
		if (error == 1)
			return (1);
	}
	if (check_egale(shell_node) == 0)
	{
		error = add_new_to_export(all, valeur);
		if (error == 1)
			return (1);
	}
	return (0);
}

int make_export(t_shell_command *shell_node, t_all *all)
{
  t_line *line_node;
	int	error;

	make_dup(shell_node);
  line_node = shell_node->command_info;
  if (line_node->next == NULL)
  {
	  printf_all_export(all);
		return (0);
	}
	error = add_val_export(shell_node, all);
	if (error == 2)
		return (0);
	if (error == 1)
		return (1);
	return (0);
}
