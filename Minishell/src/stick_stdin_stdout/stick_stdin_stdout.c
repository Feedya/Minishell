#include "../head.h"

// > stdout d une commande dans un fichier
// < stdin on donne le fichier comme stdin a 1 commande

void	initialize_shell_cmd_list(t_line **head, t_shell_command **head_cmd, t_all *all)
{
	t_line *node;
	t_shell_command *new_node;

	node = *head;
	while (node != NULL)
	{
		if (node->type == TOKEN_COMMANDE)
		{
			new_node = create_shell_cmd_node();
			if (new_node == NULL)
			{
				free_all(all);
				free_list(head);
				free_shell_cmd(head_cmd);
				exit (1);
			}
			new_node->command_info = node;
			node->fd = new_node;
			put_node_to_liste_shell_cmd(head_cmd, new_node);
		}
		node = node->next;
	}
}

void stdin_stdout(t_shell_command **shell_head, t_line **line_head, t_all *all)
{
	int	erreur;

	//premirement on met tout les stdin et stdout de tout les foncitons a default
	//comme ca le premiere cmd est fait et la derniere aussi
	make_by_default(shell_head);
	//mtn on fait les pipes
	erreur = make_pipe(shell_head);
	if (erreur == 1)
	{
		free_all(all);
		free_shell_cmd(shell_head);
		free_list(line_head);
		exit (1);
	}
	//apres les pipes on fait les rederiction parceque ils sont les plus fort
	erreur = make_rederiction_stdin_stdout(shell_head, line_head);
	if (erreur == 1)
	{
		free_all(all);
		free_shell_cmd(shell_head);
		free_list(line_head);
		exit (1);
	}
}

t_shell_command **stick_stdin_stdout(t_line **head, t_all *all)
{
	t_shell_command **head_cmd;
	head_cmd = malloc_head_shell_cmd();
	if (head_cmd == NULL)
	{
		free_all(all);
		free_list(head);
		exit (1);
	}
	initialize_shell_cmd_list(head, head_cmd, all);
	stdin_stdout(head_cmd, head, all);
	return (head_cmd);
}
