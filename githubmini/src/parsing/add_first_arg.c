#include "../head.h"

void	add_first_arg(int	*index, t_all *all, t_line **head)
{
	int	i;

	i = *index;
	if ((all->line[i] == '>' && all->line[i + 1] != '>') || (all->line[i] == '<' && all->line[i + 1] != '<'))
	{
		add_redirect_in_out(all, head, &i);
		all->commande = 1;
	}
	else if ((all->line[i] == '>'  && all->line[i + 1] == '>') || (all->line[i] == '<' && all->line[i + 1] == '<'))
	{
		add_append_heredoc(all, head, &i);
		all->commande = 1;
	}
	else
	{
		add_commande(&i, all, head);
		all->commande = 1;
	}
}
