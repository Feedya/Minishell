#include "../head.h"

int	verification_rederictions(t_line **head)
{
	t_line *node;

	node = *head;
	while (node != NULL)
	{
		if (node->type == TOKEN_REDIRECT_IN || node->type == TOKEN_REDIRECT_OUT || node->type == TOKEN_HEREDOC || node->type == TOKEN_HEREDOC)
		{
			if (node->next == NULL)
			{
				printf("ERREUR : rien apres la rederiction\n");
				return (1);
			}
			else if (node->next->type == TOKEN_PIPE)
			{
				printf("ERREUR : un pipe ne peut pas etre un fichier dans Unix/Linux c est un charactere special\n");
				return (1);
			}
		}
		node = node->next;
	}
	return (0);
}
