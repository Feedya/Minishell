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
	return (head);
}

void	main_loop(t_all *all)
{
	t_line **head;

	head = initialize_line(all);
	//while (1)
	//{
		all->line = readline("minishell > ");
		//if (all->line == NULL)
		//	break;
		//else
		//{
			parsing(all, head);
			add_history(all->line);
		//}
		free_list(head);
		free(all->line);
		all->line = NULL;
	//}
}

int	main(int argc, char **argv, char **env)
{
	t_all *all;

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

	//MINISHELL
	//boucle readline
	//dans cette boucle la tokenisation de ma chaine
	//et l execution apres la tokenisation
	//main_loop(all);
  free_all(all);
	rl_clear_history();
	return (0);
}

void	free_list(t_line **head)
{
	t_line *new_node;
	t_line *next;

	new_node = *head;
	while (new_node != NULL)
	{
		next = new_node->next;
		free(new_node->valeur);
		new_node->valeur = NULL;
		free(new_node);
		new_node = NULL;
		new_node = next;	
	}
	free(head);
	head = NULL;
}

void	free_all(t_all *all)
{
	int	i;

	i = 0;
	if (all != NULL)
	{
		if (all->env[i] != NULL)
		{
			while (all->env[i] != NULL)
			{
				free(all->env[i]);
				all->env[i] = NULL;
				i++;
			}
		}
		i  = 0;
		if (all->path != NULL)
		{
			while (all->path[i] != NULL)
			{
				free(all->path[i]);
				all->path[i] = NULL;
				i++;
			}
			free(all->path);
			all->path = NULL;
		}
		if (all->line != NULL)
		{
			free(all->line);
			all->line = NULL;
		}
		free(all);
		all = NULL;
	}
}