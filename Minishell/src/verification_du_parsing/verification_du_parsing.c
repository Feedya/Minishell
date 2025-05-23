#include "../head.h"

void  verification_du_parsing(t_line **head, t_all *all)
{
  int erreur; //si erreur est egale a 1 sa veut dire on a 1 erreur
  erreur = remove_empty_double_and_single_quotes(head);
	if (erreur == 1)
	{
		free_all(all);
		free_list(head);
		exit (1);
	}
	remove_quotes_from_commande(head);
	fill_flag_and_commande(all, head);
  erreur = put_files(head);
  if (erreur == 1)
  {
    free_all(all);
    free_list(head);
    exit (1);
  }
	erreur = put_env_variables(head, all);
	if (erreur == 1)
	{
		free_all(all);
		free_list(head);
		exit (1);
	}
  erreur = verifier_commande(head, all);
	if (erreur == 1)
	{
		free_all(all);
		free_list(head);
		exit (1);
	}
	erreur = verifier_pipe(head);
	if (erreur == 1)
	{
		free_all(all);
		free_list(head);
		exit (1);
	}
	erreur = create_argc_of_command(head);
	if (erreur == 1)
	{
		free_all(all);
		free_list(head);
		exit (1);
	}
	/*erreur = expand_env_variables(head, all);
	if (erreur == 1)
	{
		free_all(all);
		free_list(head);
		exit (1);
	}*/
}
