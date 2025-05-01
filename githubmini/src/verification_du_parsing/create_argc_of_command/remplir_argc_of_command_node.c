#include "../../head.h"

int	remplir_argc_node_command_flag(char **argc, char *flag)
{
	int	i;
	int	c;
	int	d;

	i = 0;
	c = 0;
	d = 0;
	while(flag[i] != '\0')
	{
		if (flag[i] == ' ')
		{
			argc[c][d] = '\0';
			while (flag[i] == ' ')
				i++;
			c++;
			d = 0;
		}
		else
		{
			argc[c][d] = flag[i];
			i++;
			d++;
		}
	}
	argc[c][d] = '\0';
	return (c);
}

void remplir_argc_node_command_valeur(char **argc, t_line *node, int taille)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	if (taille == 0)
		taille = 0;
	else
		taille++;//parceque la taille indexe le dernier qu on a remplis
	while (node != NULL && node->type != TOKEN_PIPE && node->type != TOKEN_APPEND && node->type != TOKEN_HEREDOC && node->type != TOKEN_REDIRECT_IN && node->type != TOKEN_REDIRECT_OUT)
	{
		while (node->valeur[i] != '\0')
		{
			argc[taille][d] = node->valeur[i];
			i++;
			d++;
		}
		argc[taille][d] = '\0';
		taille++;
		d = 0;
		i = 0;
		node = node->next;
	}
	argc[taille] = NULL;
}

int remplir_argc_of_command_node(t_line *node)
{
  int taille;

	taille = 0;
  if (node->flag != NULL)
    taille = remplir_argc_node_command_flag(node->argc, node->flag);
	remplir_argc_node_command_valeur(node->argc, node->next, taille);
	return (0);
}