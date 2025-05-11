#include "../../head.h"

// : on compare 2 string line et delimiteur
int	est_egale(char *line, char *delimiteur)
{
	int	i;

	i = 0;
	while (delimiteur[i] != '\0' && line[i] != '\0' && delimiteur[i] == line[i])
		i++;
	if (line[i] == '\0' && delimiteur[i] == '\0')
		return (1);
	return (0);
}

// : ici on va lire en boucle on va ecrire avec write dans fd[1]
// : avec la fonction "est_egale" on va comparer avec le delimiteur 
int	give_cmd_stdin_heredoc(int *fd, char *delimiteur)
{
	char *line;
	int	taille;

	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (est_egale(line, delimiteur) == 1)
			break;
		else
		{
			taille = ft_strlen(line);
			write(fd[1], line, taille);
			write(fd[1], "\n", 1);
		}
		free(line);
	}
	close(fd[1]);
	return (0);
}

//<< heredoc
//on doit creer un pipe[fd[2]] pour pouvoir lire depuis fd[1](terminal)
//et donner dans le fd[1](commande)
//on va le donner grace au "write" on va writer dans le fd[1]
//et ca va aller dans le fd[0] qui se trouve comme stdin de la commande
int	make_redirect_heredoc(t_shell_command *shell_node, t_line *line_node)
{
	char *delimiteur;
	int fd[2];

	if (line_node->next != NULL)
		delimiteur = line_node->next->valeur;
	else
		return (1);
	if (pipe(fd) < 0)
		return (1);
	
	shell_node->stdin = fd[0];
	give_cmd_stdin_heredoc(fd, delimiteur);
	return (0);
}
