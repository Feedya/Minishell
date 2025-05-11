#include "../../head.h"

int verifier_if_rederiction(t_line *node)
{
  if (node == NULL)
    printf("erreur bizzare (verifier_if_rederiction)\n");
	while (node != NULL && node->type != TOKEN_PIPE)
	{
		if (node->type == TOKEN_APPEND || node->type == TOKEN_HEREDOC || node->type == TOKEN_REDIRECT_IN || node->type == TOKEN_REDIRECT_OUT)
			return (1);
    node = node->next;
	}
	return (0);
}

int	make_append(t_line *node, t_shell_command *shell_node)
{
  (void)node;
  (void)shell_node;
  return (0);
}

int	make_rediriction(t_shell_command *shell_node)
{
	t_line *line_node;
	line_node = shell_node->command_info;
	while (line_node != NULL && line_node->type != TOKEN_PIPE)
  {
    if (line_node->type == TOKEN_REDIRECT_IN)
    {
      make_redirect_in(shell_node, line_node);
    }
    else if (line_node->type == TOKEN_REDIRECT_OUT)
		{
		  make_redirect_out(shell_node, line_node);
		}
		else if (line_node->type == TOKEN_APPEND)
    {
		  make_redirect_append(shell_node, line_node);
		}
    else if (line_node->type == TOKEN_HEREDOC)
    {
		  make_redirect_heredoc(shell_node, line_node);
		}
    line_node = line_node->next;
  }
	return (0);
}


int make_rederiction_stdin_stdout(t_shell_command **shell_head, t_line **line_head)
{
  t_line *node;
  t_shell_command *shell_node;

  shell_node = *shell_head;
  node = shell_node->command_info;  
  while (shell_node != NULL)
  {
    if (verifier_if_rederiction(node) == 1)
    {
			if (make_rediriction(shell_node) == 1)
				return (1);
    }
    shell_node = shell_node->next;
  }
  (void)node;
  (void)line_head;
  return (0);
}

	/*
  node = node->next;
  while (node != NULL && node->type != TOKEN_COMMANDE)
  {
    if (node->type == TOKEN_REDIRECT_IN)
    {
							
    }  
    
    else if (node->type == TOKEN_REDIRECT_OUT)
    
    else if (node->type == TOKEN_APPEND)

    else if (node->type == TOKEN_HEREDOC)
    */

/*
dernière_commande = NULL
shell_commande_courante = première_commande_shell

Pour chaque token dans t_line:
  Si token est une COMMANDE:
    dernière_commande = token
    shell_commande_courante = trouver shell_cmd correspondant à ce token
  
  Si token est une REDIRECTION (>, <, >>, <<):
    Si dernière_commande n'est pas NULL:
      token_suivant = fichier associé à la redirection
      Appliquer la redirection au shell_commande_courante*/