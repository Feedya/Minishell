#include "../../head.h"

//>>
// : on doit creer un fichier et donner le stdout de la cmd
// : O_APPEND : mettre cursor sur la fin dans file
// : O_WRONLY : que en ecriture
// : O_CREAT  : le creer si existe pas
int make_redirect_append(t_shell_command *shell_node, t_line *line_node)
{
  int fd;
  char  *file;

  if (line_node->next != NULL)
    file = line_node->next->valeur;
  else
    return (1);
  fd = open(file, O_APPEND | O_WRONLY | O_CREAT, 0644);
  if (fd < 0)
  {
		printf("open a bader dans make_redirect_append\n");
		return (1);
	}
	shell_node->stdout = fd;
	return (0);
}
