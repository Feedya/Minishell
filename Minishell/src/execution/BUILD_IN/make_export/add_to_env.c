#include "../../../head.h"

char  **malloc_copy_env_export(char **env, char *valeur)
{
  char  **copy;

  int i;
  int c;

  c = 0;
	i = 0;
  while (env[c] != NULL)
    c++;
  copy = malloc(sizeof(char *) * (c + 2));
  if (copy == NULL)
    return (NULL);
  c = 0;
	while (env[c] != NULL)
  {
    i = 0;
    while (env[c][i] != '\0')
      i++;
		copy[c] = malloc(sizeof(char) * (i + 1));
		if (copy[c] == NULL)
		{
			free_double_char(copy);
			return (NULL);
		}
		c++;
	}
	i = ft_strlen(valeur);
	copy[c] = malloc(sizeof(char) * (i + 1));
	c++;
	copy[c] = NULL;
	return (copy);
}

void	fill_copy_env(char **copy_env, char **env, char *valeur)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (env[i] != NULL)
	{
		c = 0;
		while (env[i][c] != '\0')
		{
			copy_env[i][c] = env[i][c];
			c++;
		}
		copy_env[i][c] = '\0';
		i++;
	}
	c = 0;
	while (valeur[c] != '\0')
	{
		copy_env[i][c] = valeur[c];
		c++;
	}
	copy_env[i][c] = '\0';
	i++;
	copy_env[i] = NULL;
}

int	add_to_env(t_shell_command *shell_node, t_all *all, char *valeur)
{
  char **copy_env;
  copy_env = malloc_copy_env_export(all->env, valeur);
	if (copy_env == NULL)
		return (1);
	fill_copy_env(copy_env, all->env, valeur);
	printf("apres fill copy malloc\n");
	free_double_char(all->env);
	all->env = copy_env;
	(void) shell_node;
	return (0);
}
