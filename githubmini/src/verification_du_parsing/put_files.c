#include "../head.h"

//on va mettre le noeud apres les redirection >< a TOKEN_FICHIER pour dire que c est des fichiers
int	put_files(t_line **head)
{
  t_line *node;
  t_line *next;

  node = *head;
  while (node != NULL)
  {
    if (node->type == TOKEN_REDIRECT_IN || node->type == TOKEN_REDIRECT_OUT)
    {
			if (node->next == NULL) //si on a pas de prochain noeud c est faux
			{
        printf("bash: syntax error near unexpected token 'newline'\n");
      	return (1);
      }
      next = node->next;
      if (next->type == TOKEN_PIPE || next->type == TOKEN_REDIRECT_IN || next->type == TOKEN_REDIRECT_OUT || next->type == TOKEN_APPEND || next->type == TOKEN_HEREDOC)
      {
        printf("bash: syntax error near unexpected token '%s'\n", next->valeur);
        return (1);
      }
      if (next->type)
			next->type = TOKEN_FILES;
    }
		node = node->next;
  }
	return (0);
}