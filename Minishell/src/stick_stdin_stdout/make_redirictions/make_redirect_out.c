#include "../../head.h"

//>
// : ici on doit ouvrir un fichier et ecrire a l interieur
// : en effacant tout et creer le fichier si besoin
// : O_CREAT : creer le fichier si il n existe pas
// : O_TRUNC : tout effacer se qui se trouve a l interieur
// : O_WRONLY: que en ecriture 
int make_redirect_out(t_shell_command *shell_node, t_line *line_node)
{
  int fd;
  char *file;

  if (line_node->next != NULL)
    file = line_node->next->valeur;
  else
    return (1);
  fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
  if (fd < 0)
  {
    printf("open a bader dans make_redirect_out\n");
    return (1);
  }
  shell_node->stdout = fd;
  return (0);
}
