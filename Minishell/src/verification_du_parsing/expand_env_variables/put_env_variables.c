#include "../../head.h"

int count_how_much_env_there_is(char *str)
{
  int i;
  int counter;

  i = 0;
  counter = 0;
  while (str[i] != '\0')
  {
    if (str[i] == '$' && str[i + 1] != '\0' && str[i + 1] != ' ')
      counter++;
    i++;
  }
  return (counter);
}

int env_variables(t_line *node, t_all *all, char *str)
{
  int counter;
  int taille;
  char  *expanded_str;

  counter = count_how_much_env_there_is(str);
  if (counter == 0)
    return (0);
  taille = count_taille_str_with_env(str, all);
  if (taille == -1)
    return (1);
  expanded_str = malloc(sizeof(char) * (taille + 1));
  printf("taille : %d\n", taille);
  if (expanded_str == NULL)
    return (1);
  if (fill_expanded_str(expanded_str, str, all) == 1)
    return (1);
  free(node->valeur);
  node->valeur = expanded_str;
  (void)node;
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
      error = env_variables(node, all, node->valeur);
      if (error == 1)
        return (1);
    }
    node = node->next;
  }
  return (0);
}
