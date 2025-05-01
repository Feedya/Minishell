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

void  parsing(t_all *all, t_line **head)
{
  int i;

  i = 0;
	while (all->line[i] == ' ') //on saute les espace du debut
		i++;
	add_first_arg(&i, all, head);
  while (all->line[i] != '\0')
  {
		if (all->commande == 1)//on avait un commande juste avant on cherche une redericiton ou un arguments
		{
			if (all->line[i] == '"')
				add_double_quotes(all, head, &i);
			else if (all->line[i] == '\'')
				add_single_quotes(all, head, &i);
			else if ((all->line[i] == '>' && all->line[i + 1] != '>') || (all->line[i] == '<' && all->line[i + 1] != '<'))
				add_redirect_in_out(all, head, &i);
			else if ((all->line[i] == '>'  && all->line[i + 1] == '>') || (all->line[i] == '<' && all->line[i + 1] == '<'))
				add_append_heredoc(all, head, &i);
			else if (all->line[i] == '|')
			{
				add_pipe(all, head, &i);
				all->commande = 0; // apres un pipe on peut avoir un commande donc je met all->commande a 0
			}
			else if (all->line[i] == ' ')
				i++;
			else
				add_word(all, head, &i);
		}
		else
		{
			while (all->line[i] == ' ')
				i++;
			if (all->line[i] != '\0')
				add_commande(&i, all, head);
		}
	}
}
