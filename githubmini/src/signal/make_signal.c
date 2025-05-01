#include "../head.h"

char *read_line(void)
{
  char *line;

  line = readline("minishell > ");
  if (line == NULL)
  {;
    printf("La ligne est vide\n");
    exit (1);
  }
  add_history(line);
  return (line);
}

void ctrl_c(int signal)
{
  if (signal == SIGINT)
  {
    rl_replace_line("\n", 0);
    rl_on_new_line();
    rl_redisplay();
  }
}

void  make_signal(void)
{
  struct sigaction sa;
  sigset_t set;

  if (sigemptyset(&set) == -1)
  {
    printf("Probleme de sigemptyset controls(void)\n");
    rl_on_new_line();
    return ;
  }  
  sigaddset(&set, SIGINT);
  sa.sa_handler = ctrl_c;
  sa.sa_mask = set;
  sa.sa_flags = 0;
  if (sigaction(SIGINT, &sa, NULL) == -1)
  {
    printf("Erreur de sigaction controls(void)\n");
    rl_on_new_line();
    return ;
  }
}