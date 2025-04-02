#include "../../head.h"

int count_big_taille_of_argc_command(t_line *node)
{
  int taille;
  int i;

  i = 0;
  taille = 0;
  if (node->flag != NULL)
  {
		taille++;
    while (node->flag[i] != '\0')
    {
      if (node->flag[i] == ' ')
			{
				while (node->flag[i] == ' ')
					i++;
				taille++;
			}
			else
				i++;
    }
  }
	node = node->next;
  while (node != NULL)
	{
		if (node->type == TOKEN_PIPE || node->type == TOKEN_APPEND || node->type == TOKEN_HEREDOC || node->type == TOKEN_REDIRECT_IN || node->type == TOKEN_REDIRECT_OUT)
			break;
		node = node->next;
		taille++;
	}
	return (taille);
}

int	malloc_flag_part_command_argc(char **argc, int *index, char *flag)
{
	int	i;
	int c;
	int	taille;

	taille = 0;
	c = *index;
	i = 0;
	while (flag[i] != '\0')
	{
		if (flag[i] == ' ')
		{
			argc[c] = malloc(sizeof(char) * (taille + 1));
			if (argc[c] == NULL)
				return (-1);
			c++;
			while (flag[i] == ' ')
				i++;
			taille = 0;
		}
		else
		{
			i++;
			taille++;
		}
	}
	*index = c;
	return (taille);
}

int	malloc_valeur_part_command_argc(t_line *node, char **argc, int *index)
{
	int	taille;
	int	c;

	c = *index;
	taille = 0;
	while (node != NULL)
	{
		if (node->type == TOKEN_APPEND || node->type == TOKEN_HEREDOC || node->type == TOKEN_PIPE || node->type == TOKEN_REDIRECT_IN || node->type == TOKEN_REDIRECT_OUT)
			break ;
		while (node->valeur[taille] != '\0')
			taille++;
		argc[c] = malloc(sizeof(char) * (taille + 1));
		if (argc[c] == NULL)
			return (1);
		c++;
		taille = 0;
		node = node->next;
	}
	argc[c] = NULL;
	return (0);
}

//Cette fonction doit prendre les flags et les valeur des prochains noeuds et mettre dans un char **argc pour pouvoir faire execve
int malloc_small_parts_command_argc(char **argc, t_line *node, char *flag)
{
	int taille;
	int	c;

	taille = 0;
	c = 0;
	if (flag != NULL)
		taille = malloc_flag_part_command_argc(argc, &c, flag);
	if (taille > 0)
	{
		argc[c] = malloc(sizeof(char) * (taille + 1));
		if (argc[c] == NULL)
			return (1);
		c++;
	}
	else if (taille == -1)//si malloc dans malloc_valeur_part_commande_argc n a pas fonctionnerr
		return (1);
	
	taille = 0;
	node = node->next;
	if (malloc_valeur_part_command_argc(node, argc, &c) == 1)
		return (1);
	return (0);
}

int malloc_argc_of_node(t_line *node)
{
  int big_taille;
  int erreur;

  erreur = 0;
  big_taille = count_big_taille_of_argc_command(node);
	if (big_taille == 0)
	{
		node->argc = NULL;
		return (0);
	}
  node->argc = malloc(sizeof(char **) * (big_taille + 1));
  if (node->argc == NULL)
    return (1);
  erreur = malloc_small_parts_command_argc(node->argc, node, node->flag);
  if (erreur == 1)
    return (1);
  return (0);
}

int create_argc(t_line *node)
{
  int erreur;

  erreur = malloc_argc_of_node(node);//on va mallocer le char **argc dans notre noeud commande
	if (node->argc == NULL)
		return (0);
  if (erreur == 1)
    return (1);
	erreur = remplir_argc_of_command_node(node);//on va remplir l espace qu on a malloc char **argc
	return (0);
}

int create_argc_of_command(t_line **head)
{
  t_line *node;

  node = *head;
  while (node != NULL)
  {
    if (node->type == TOKEN_COMMANDE)
    {
		  if (create_argc(node) == 1)
      	return (1);
		}
    node = node->next;
  }
  return (0);
}