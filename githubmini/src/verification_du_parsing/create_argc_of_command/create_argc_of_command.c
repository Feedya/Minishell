#include "../../head.h"

int count_big_taille_of_argc_command(t_line *node)
{
  int taille;
  int i;

  i = 0;
  taille = 0;
	if (node->commande != NULL)
		taille++;
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
	if (taille > 0)
	{
		argc[c] = malloc(sizeof(char) * (taille + 1));
		if (argc[c] == NULL)
			return (1);
		c++;
	}
	*index = c;
	return (0);
}

int	malloc_valeur_part_command_argc(t_line *node, char **argc, int *index)
{
	int	taille;
	int	c;

	c = *index;
	taille = 0;
	if (node->next != NULL)
		node = node->next;
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
/*int malloc_small_parts_command_argc(char **argc, t_line *node, char *flag)
{
	int taille;
	int	c;
	int	error;

	taille = 0;
	c = 0;
	error = 0;
	//on malloc le premier char * de la commande
	while (node->commande[taille] != '\0')
		taille++;
	argc[c] = malloc(sizeof(char) * (taille + 1));
	if (argc[c] == NULL)
		return (1);
	c++;

	//on malloc le flag
	if (flag != NULL)
	{
		error = malloc_flag_part_command_argc(argc, &c, flag);
	}
	if (error == 1)//si malloc dans malloc_valeur_part_commande_argc n a pas fonctionnerr
	{
		printf("deuxieme if\n");
		return (1);
	}
	//verification si on a qun un seul noeud
	if (node->next == NULL)
	{
		printf("troisieme if\n");
		return (0);
	}
	//on malloc dans argc pour les valeur des prochain noeuds
	if (malloc_valeur_part_command_argc(node, argc, &c) == 1)
	{
		return (1);
	}
	if (node->argc == NULL)
		printf("argc est null\n");
	return (0);
}*/

int	malloc_commande_argc(char **argc, t_line *node, int *big_taille_index)
{
	int	index;
	int	i;

	i = 0;
	index = *big_taille_index;
	if (node->type == TOKEN_COMMANDE)
	{
		while (node->commande[i] != '\0')
			i++;
		argc[index] = malloc(sizeof(char) * (i + 1));
		if (argc[index] == NULL)
			return (1);
		index++;
		*big_taille_index = index;
		return (0);
	}
	printf("commande dans create_argc_of_command.c dans la fonction malloc_commande_argc\n");
	printf("normalement cette erreur ne devrait jamais arriver\n");
	printf("c est parceque le noeud n est pas une commande\n");
	return (1);
}

int	malloc_flag_argc(char *flag, char **argc, int *index)
{
	int	taille;
	int	i;
	int	c;

	taille = 0;
	i = 0;
	c = *index;
	while (flag[i] != '\0')
	{
		if (flag[i] == ' ')
		{
			while (flag[i] == ' ')
				i++;
			argc[c] = malloc(sizeof(char) * (taille + 1));
			if (argc[c] == NULL)
				return (1);
			taille = 0;
			c++;
		}
		else
		{
			i++;
			taille++;
		}
	}
	if (taille > 0)
	{
		argc[c] = malloc(sizeof(char) * (taille + 1));
		if (argc[c] == NULL)
			return (1);
		c++;
	}
	argc[c] = NULL;
	*index = c;
	return (0);
}

int	malloc_valeur_argc(t_line *node, char **argc, int *i)
{
	int	index;
	int	taille;

	taille = 0;
	index = *i;
	while (node != NULL && (node->type == TOKEN_WORD || node->type == TOKEN_DOUBLE_QUOTES || node->type == TOKEN_SINGLE_QUOTES))
	{
		taille = 0;
		while (node->valeur[taille] != '\0')
			taille++;
		argc[index] = malloc(sizeof(char) * (taille + 1));
		if (argc[index] == NULL)
			return (1);
		index++;
		node = node->next;
	}
	*i = index;
	return (0);
}

int malloc_small_parts_command_argc(t_line *node, char *flag, char **argc)
{
	int	error;
	int	index;

	index = 0;
	error = 0;
	
	if (malloc_commande_argc(argc, node, &index) == 1)
		return (1);
	
	if (node->flag != NULL)
		error = malloc_flag_argc(flag, argc, &index);
	if (error == 1)
		return (1);

	if (node->next != NULL)
	{
		node = node->next;
		if (node != NULL && (node->type == TOKEN_DOUBLE_QUOTES || node->type == TOKEN_SINGLE_QUOTES || node->type == TOKEN_WORD))
		{
			error = malloc_valeur_argc(node, argc, &index);
		}
		if (error == 1)
			return (1);
	}
	return (0);
}

int malloc_argc_of_node(t_line *node)
{
  int big_taille;
  int erreur;
	int	i;
	char	**argc;

	i = 0;
  erreur = 0;
  big_taille = count_big_taille_of_argc_command(node);
	if (big_taille == 0)
	{
		node->argc = NULL;
		return (0);
	}
  node->argc = malloc((sizeof(char *)) * (big_taille + 2));
  if (node->argc == NULL)
    return (1);
	while (i <= big_taille)
	{
		node->argc[i] = NULL;
		i++;
	}
	argc = node->argc;
  erreur = malloc_small_parts_command_argc(node, node->flag, argc);
  if (erreur == 1)
    return (1);
	return (0);
}

int create_argc(t_line *node)
{
  int erreur;

  erreur = malloc_argc_of_node(node);//on va mallocer le char **argc dans notre noeud commande
	if (node->argc == NULL)
	{
		printf("dans create argc si argc est egale a NULL\n");
		return (0);
	}
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
