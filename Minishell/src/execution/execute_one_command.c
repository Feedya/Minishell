#include "../head.h"

/*
Pour enchaîner plusieurs commandes (qu'elles soient built-in ou externes) dans une pipeline, l'idée est bien de rediriger la sortie standard d'une commande vers l'entrée standard de la suivante.

Pour N commandes, vous aurez besoin de N–1 pipe(s) pour faire circuler les données :

• La première commande n'a pas d'entrée redirigée (elle lit normalement ou d'une autre source)  
• Chaque commande intermédiaire redirige son stdin (venant du pipe précédent) et son stdout (envoyé dans le pipe suivant).  
• La dernière commande lit l'entrée du pipe précédent mais envoie sa sortie normalement.

Pour les commandes externes, il faudra créer un processus enfant pour chacune et utiliser dup2() pour rediriger les file descriptors. Pour des built-in, qui s'exécutent souvent dans le processus parent, vous devrez rediriger temporairement leur stdout pour capturer la sortie et la transmettre ensuite.

En résumé, pour 5 commandes (2 built-in et 3 externes par exemple), vous n’« allumez » pas 5 pipes, mais 4 pipes reliant chaque paire de commandes. Le principe reste le même : à chaque étape, le stdout de la commande active devient le stdin de la commande suivante.
*/

void execute_one_extern_command(t_line **head)
{
  int *fd;

  fd = create_pipe();
  
}

void  one_command(t_line **head)
{
  t_line *node;

  node = *head;
  if (node->command_type == EXTERN)
  {
    execute_one_extern_command(head);
  }
  else
    execute_one_build_in_command(head);
}
