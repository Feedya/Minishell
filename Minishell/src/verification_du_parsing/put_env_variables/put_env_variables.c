#include "../../head.h"
/*
int look_if_env_exist(t_line *node, t_all *all)
{

}*/

int env_variables(t_line *node, t_all *all)
{
 //int is_valid_env;

  //s_valid_env = look_if_env_exist(node, all);
  (void)node;
  (void)all;
  return (0);
}

int put_env_variables(t_line **head, t_all *all)
{
  t_line *node;
  int error;

  error = 0;
  node = *head;
  while (node != NULL)
  {
    if (node->type == TOKEN_DOUBLE_QUOTES || node->type == TOKEN_WORD)
    {
      error = env_variables(node, all);
      if (error == 1)
        return (1);
    }
    node = node->next;
  }
  return (0);
}
