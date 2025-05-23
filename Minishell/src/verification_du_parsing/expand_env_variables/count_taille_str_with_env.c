#include "../../head.h"

char  *take_name_of_env_from_str(char *str, int index)
{
  int i;
  char  *env;
  int temp_index;

  temp_index = index + 1;
  i = 0;
  while (str[temp_index] != '\0' && str[temp_index] != ' ' && str[temp_index] != '$')
  {
    temp_index++;
    i++;
  }
  env = malloc(sizeof(char) * (i + 2));
  if (env == NULL)
    return (NULL);
  i = 1;
  env[0] = '$';
  temp_index = index + 1;
  while (str[temp_index] != '\0' && str[temp_index] != ' ' && str[temp_index] != '$')
  {
    env[i] = str[temp_index];
    i++;
    temp_index++;
  }
  env[i] = '\0';
  return (env);
}

int fount_index_of_env(char *env, t_all *all)
{
  int index;
  int i;
  int c;

  i = 0;
  c = 0;
  index = 1;
  while (all->env[i] != NULL)
  {
    c = 0;
    index = 1;
    while (all->env[i][c] == env[index])
    {
      c++;
      index++;
    }
    if (all->env[i][c] == '=' && env[index] == '\0')
      return (i);
    i++;
  }
  return (-1);
}

int count_taille_env(char *env, t_all *all)
{
  int index;
  int taille;

  taille = 0;
  index = fount_index_of_env(env, all);
  if (index == -1)
    return (0);
  taille = 0;
  while (all->env[index][taille] != '\0')
    taille++;
  return (taille);
}

int count_taille_str_with_env(char *str, t_all *all)
{
  char *env;
  int i;
  int taille;

  taille = 0;
  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] == '$' && str[i + 1] != '\0' && str[i + 1] != ' ')
    {
      env = take_name_of_env_from_str(str, i);
      if (env == NULL)
        return (-1);
      taille = taille + count_taille_env(env, all);
      i++;
      while (str[i] != '\0' && str[i] != ' ' && str[i] != '$')
        i++;
    }
    else
    {
      taille++;
      i++;
    }
  }
  free(env);
  return (taille);
}

