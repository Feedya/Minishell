#include "../../head.h"

void	fill_command_argc(char *command, char **argc)
{
	int	i;

	i = 0;
	while (command[i] != '\0')
	{
		argc[0][i] = command[i];
		i++;
	}
	argc[0][i] = '\0';
}

void	fill_flag_argc(char *flag, char **argc, int *i)
{
	int	index;
	int	d;
	int	c;

	index = *i;
	d = 0;
	c = 0;
	while (flag[d] != '\0')
	{
		if (flag[d] == ' ')
		{
			argc[index][c] = '\0';
			while (flag[d] == ' ')
				d++;
			index++;
			c = 0;
		}
		else
		{
			argc[index][c] = flag[d];
			d++;
			c++;
		}
	}
	if (c > 0)
	{
		argc[index][c] = '\0';
		index++;		
	}
	*i = index;
}

void	fill_valeur_argc(t_line *node, char **argc, int *i)
{
	int	index;
	int	c;

	index = *i;
	c = 0;
	while (node != NULL && (node->type == TOKEN_DOUBLE_QUOTES || node->type == TOKEN_SINGLE_QUOTES || node->type == TOKEN_WORD))
	{
		while (node->valeur[c] != '\0')
		{
			argc[index][c] = node->valeur[c];
			c++;
		}
		argc[index][c] = '\0';
		index++;
		c = 0;
		node = node->next;
	}
	if (c > 0)
		argc[index][c] = '\0';
}

int remplir_argc_of_command_node(t_line *node)
{
	int	index;
	char **argc;

	argc = node->argc;
	index = 1;
	if (node->type == TOKEN_COMMANDE)
		fill_command_argc(node->commande, argc);
	if (node->flag != NULL)
		fill_flag_argc(node->flag, argc, &index);
	node = node->next;
	if (node != NULL && (node->type == TOKEN_DOUBLE_QUOTES || node->type == TOKEN_SINGLE_QUOTES || node->type == TOKEN_WORD))
		fill_valeur_argc(node, argc, &index);
	return (0);
}
