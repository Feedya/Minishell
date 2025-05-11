#include "../../head.h"

//<
// : ici on doit ouvrir le fichier en lecture
// : O_RDONLY : read only
int	make_redirect_in(t_shell_command *shell_node, t_line *line_node)
{
  char *file;
  int fd;

  if (line_node->next != NULL)
    file = line_node->next->valeur;
	else
		return (1);
  fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("bash: %s: No such file or directory\n", file);
		return (1);
	}
	shell_node->stdin = fd;
	return (0);
}
