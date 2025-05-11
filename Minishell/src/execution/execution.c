#include "../head.h"

int execution(t_line **line_head, t_shell_command **shell_head, t_all *all)
{
  t_shell_command *shell_node;
  int error;

  shell_node = *shell_head;
  while (shell_node != NULL)
  {
    if (shell_node->command_info->command_type == BUILD_IN)//BUILD_IN
    {
      error = make_build_in_command(shell_node, all);
			if (error == 1)
			{
				free_all(all);
				free_list(line_head);
				free_shell_cmd(shell_head);
				exit (1);
			}
    }
    if (shell_node->command_info->command_type == EXTERN)
    {
      error = make_extern_command(shell_node, all);//EXTERN
			if (error == 1)
			{
				free_all(all);
				free_list(line_head);
				free_shell_cmd(shell_head);
				exit (1);
			}
		}
    shell_node = shell_node->next;
  }
  return (0);
}
