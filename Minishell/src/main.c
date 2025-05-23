#include "head.h"

t_line **initialize_line(t_all *all)
{
	t_line **head;

	head = malloc(sizeof(t_line *));
	if (head == NULL)
	{
		free_all(all);
		exit (1);
	}
	*head = NULL;
	return (head);
}

t_line	**main_loop(t_all *all)
{
	t_line **head_line;
	t_shell_command **head_shell;

	head_line = initialize_line(all);
	all->line = readline("minishell > ");
	if (all->line == NULL)
		return NULL;
	parsing(all, head_line);
	verification_du_parsing(head_line, all);
	head_shell = stick_stdin_stdout(head_line, all);
	execution(head_line, head_shell, all);
	print_list(head_line);
	/*printf("--------------------------------\n");
	print_env(all);
	printf("--------------------------------\n");*/
	print_double_char(all->export);
	add_history(all->line);
	print_env(all);
	//}c
	free_shell_cmd(head_shell);
	free(all->line);
	all->line = NULL;
	return (head_line);
}

int	main(int argc, char **argv, char **env)
{
	t_all *all;
	t_line **head;

	(void) argc;
	(void) argv;
	//CMALLOC DE TOUT
	all = malloc_struct_all();
	
	//COPIE CHAR **ENV DANS TOUT
	//DEUX CAS A VERIFIER SI L ENVIRONNEMENT EXISTE OU SI IL N EXISTE PAS
	if (env[0] == NULL)
		create_env_in_all(all);//pour le cas si env n existe pas
	else
		copy_env_in_all(all, env); //pour le cas si env n existe pas
	//ON CREE LE CHAR **PATH 
	copy_path(all);//creation du path pour les commandes externe

	//ON DOIT METTRE LES SIGNAUX
	make_signal();// pour ctrl + d/l/c

	// MAIN LOOP
	head = main_loop(all);
	free_list(head);
	free_all(all);
	rl_clear_history();
	return (0);
}
