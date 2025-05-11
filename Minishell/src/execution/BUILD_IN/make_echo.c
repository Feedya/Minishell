#include "../../head.h"

void make_build_in_echo(t_shell_command *shell_node)
{
  t_line *line_node;
  int flag;

  flag = 0;
  line_node = shell_node->command_info;
  if (line_node->flag != NULL)
    flag = 1;
  line_node = line_node->next;
  while (line_node != NULL && (line_node->type == TOKEN_WORD || line_node->type == TOKEN_SINGLE_QUOTES || line_node->type == TOKEN_DOUBLE_QUOTES))
  {
    printf("%s", line_node->valeur);
    line_node = line_node->next;
    if(line_node != NULL && (line_node->type == TOKEN_WORD || line_node->type == TOKEN_SINGLE_QUOTES || line_node->type == TOKEN_DOUBLE_QUOTES))
      printf(" ");
  }
  if (flag == 0)
    printf("\n");
}
