#include "../head.h"

/*
echo with option -n
◦ cd with only a relative or absolute path
◦ pwd with no options
◦ export with no options
◦ unset with no options
◦ env with no options or arguments
◦ exit
*/

int	find_end_of_double_quotes(char *line, int *index)
{
	int	i;

	i = *index;
	while (line[i] != '\0' && line[i] != '"')
		line++;
		i++;
	printf("%d\n", i);	
}

void	add_double_quotes(t_all *all, t_line **head, int *index)
{
	int	i;
	char *line;
	int	index_fin;
	int	start_index;

	i = *index;
	start_index = *index;
	i++;
	line = all->line;
	index_fin = find_end_of_double_quotes(line, &i);
	all->commande = 0;
}

void  parsing(t_all *all, t_line **head)
{
  int i;

  i = 0;
	add_commande(&i, all, head);
  while (all->line[i] != '\0')
  {
		if (all->commande == 1)//on avait un commande juste avant on cherche une redericiton ou un arguments
		{
			if (all->line[i] == '"')
				add_double_quotes(all, head, &i);
		}
		else
		{
			
		}
  }
 t_line *node;
 node = *head;
 while (node != NULL)
 {
	printf("valeur : %s\n", node->valeur);
	node = node->next;
 }
}
