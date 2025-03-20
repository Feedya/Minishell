#include "../head.h"

/*(echo with option -n
◦ cd with only a relative or absolute path
◦ pwd with no options
◦ export with no options
◦ unset with no options
◦ env with no options or arguments
◦ exit with no option)*/

int	ft_comparer(char *)

int	see_if_build_in(t_line *node)
{
	int	i;

	i = ft_comparer(node->valeur, "echo"); echo -n
}

int verifier_commande(t_line **head, t_all *all)
{
	int	build_in_or_extern; // if 1 = build in : if 0 = extern
	t_line *node;

	node = *head;
	while (node != NULL)
	{
		if (node->type == TOKEN_COMMANDE)
		{
			build_in_or_extern = see_if_build_in(node);
		}
		node = node->next;
	}
}