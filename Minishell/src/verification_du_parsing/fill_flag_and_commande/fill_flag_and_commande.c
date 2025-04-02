#include "../../head.h"

int	count_start_char_flag_commande(char *str)
{
	int start;

	start = 0;
	while (str[start] != '\0' && str[start] != '-')
		start++;
	while (str[start] == ' ')
		start++;
	if (str[start] == '\0')
		return (-1);
	return (start);
}

int	count_taille_char_flag_commande(char *str, int start)
{
	int	taille;

	taille = 0;
	while (str[start] != '\0')
	{
		if (str[start] == ' ')
		{
			taille++;
			while (str[start] == ' ')
				start++;
		}
		else
		{
			start++;
			taille++;
		}
	}
	start--;
	taille--;
	while (str[start] == ' ')
	{
		taille--;
		start--;
	}
	taille++;
	return (taille);
}

void	copy_flag_from_valeur(char *valeur, char *flag, int taille, int start)
{
	int	c;

	c = 0;
	while (c != taille)
	{
		if (valeur[start] == ' ')
		{
			flag[c] = ' ';
			while (valeur[start] == ' ')
				start++;
			if (valeur[start] == '\0')
			{
				flag[c] = '\0';
				break;
			}
			c++;
		}
		else
		{
			flag[c] = valeur[start];
			c++;
			start++;
		}
	}
	flag[c] = '\0';
}

void	create_char_flag_node(t_line *node, t_line **head, t_all *all)
{
	int	start;
	int	taille;

	start = count_start_char_flag_commande(node->valeur);//start va indexer le ou le flag commence
	if (start == -1)
	{
		node->flag = NULL;
		return ;
	}
	taille = count_taille_char_flag_commande(node->valeur, start);//on va compter la taille du flag en sautant les espaces
	node->flag = malloc(sizeof(char) * (taille + 1));
	if (node->flag == NULL)
	{
		free_all(all);
		free_list(head);
		exit (1);
	}
	copy_flag_from_valeur(node->valeur, node->flag, taille, start);//on va copier le flag de valeur dans le char *flag
}

//ici on va diviser notre commande pour lui remplir le char *commande et le char *flag
void  fill_flag_and_commande(t_all *all, t_line **head)
{
  t_line *node;

  node = *head;
  while (node != NULL)
  {
    if (node->type == TOKEN_COMMANDE)
    {
			create_char_commande_node(node, head, all);
			create_char_flag_node(node, head, all);
		}
    node = node->next;
  }
}
