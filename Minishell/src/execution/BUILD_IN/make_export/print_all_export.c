#include "../../../head.h"

void  printf_all_export(t_all *all)
{
  int i;
  int c;

  i = 0;
  c = 0;
  while (all->env[i] != NULL)
  {
    c = 0;
    printf("declare -x ");
    while (all->env[i][c] != '=')
    {
      printf("%c", all->env[i][c]);
      c++;
    }
    c++;
    printf("=\"");
    while (all->env[i][c] != '\0')
    {
      printf("%c", all->env[i][c]);
      c++;
    }
    printf("\"\n");
	  i++;
  }
  print_char_export(all->export);
}