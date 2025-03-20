#include "../head.h"

void  malloc_create_env_in_all_two(t_all *all)
{
  if ((all->env[3] = malloc(sizeof(char) * 14)) == NULL) // USER
  {
    free_all(all);
    exit (1);
  }
  if ((all->env[4] = malloc(sizeof(char) * 8)) == NULL) //SHLVL
  {
    free_all(all);
    exit (1);
  }
  all->env[5] = NULL;
}

void  malloc_create_env_in_all(t_all *all)
{
  all->env = malloc(sizeof(char *) * (6));
  if (all->env == NULL)
  {
    free_all(all);
    exit (1);
  }
  if ((all->env[0] = malloc(sizeof(char) * 142)) == NULL) //PATH
  {
    free_all(all);
    exit (1);
  }
  if ((all->env[1] = malloc(sizeof(char) * 20)) == NULL) //HOME
  {
    free_all(all);
    exit (1);
  }
  if ((all->env[2] = malloc(sizeof(char) * 37)) == NULL) // PWD
  {
    free_all(all);
    exit (1);
  }
  malloc_create_env_in_all_two(all);
}

void  fill_create_env_in_all(t_all *all)
{
  ft_strcpy(PATH_VALUE, all->env[0]);
  ft_strcpy(HOME_VALUE, all->env[1]);
  ft_strcpy(PWD_VALUE, all->env[2]);
  ft_strcpy(USER_VALUE, all->env[3]);
  ft_strcpy(SHLVL_VALUE, all->env[4]);
}

void  create_env_in_all(t_all *all)
{
  malloc_create_env_in_all(all);
  fill_create_env_in_all(all);
}