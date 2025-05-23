#include "../../../head.h"

//chdir
// int chdir(const char *path);
// path: A string representing the directory path you want to change to.
//0 succes -1 error
/*Changes the current working directory of the calling process to the specified path
Common errors:
ENOENT: The directory does not exist
EACCES: Permission denied
ENOTDIR: The path is not a directory*/

//getcwd
// char *getcwd(char *buf, size_t size);
// buf: A buffer to store the path string
// size: The size of the buffer in bytes
/*Retrieves the absolute pathname of the current working directory
In a shell, it's used to:
Track the current directory
Update PWD environment variable
Save previous directory as OLDPWD
Handle relative path resolution*/

//getenv

//pour faire cd il faut 
//faut prendre le path de mtn avec getcwd
//essayer de rentrer dans un chdir
//si on arrive
//mettre le oldpwd et le nouveau pwd dans les char **env
//si on arrive pas rien faire et ecrire le message d erreur

int	make_chdir(char *destination)
{
	int	error;

	error = chdir(destination);
	if (error == 1)
		return (1);
	if (error == -1)
	{
		printf("bash: cd: %s: No such file or directory\n", destination);
		return (-1);
	}
	else
		return (0);
}

int	switch_pwd_oldpwd(t_all *all, char *destination, char *oldpwd)
{
	int	error;

	error = add_pwd_oldpwd(oldpwd, all->env, 1);
  if (error == 1)
	{
		free(oldpwd);
		free(destination);
		return (1);
	}
	error = add_pwd_oldpwd(destination, all->env, 0);
	if (error == 1)
	{
		free(oldpwd);
		free(destination);
		return (1);
	}
	return (0);
}

int	cd_to_path(t_shell_command *shell_node, t_all *all)
{
	char *oldpwd;
	char *newpwd;
	char *destination;
	t_line *node;
	int	error;

	node = shell_node->command_info->next;
	destination = node->valeur;
	oldpwd = getcwd(NULL, 0);
	error = make_chdir(destination);
	if (error == 1)
	{
		free(oldpwd);
		return (1);
	}
	if (error == -1)
	{
		free(oldpwd);
		return (0);
	}
	newpwd = getcwd(NULL, 0);
	error = switch_pwd_oldpwd(all, newpwd, oldpwd);
	free(oldpwd);
	free(newpwd);
	if (error == 1)
		return (1);
	error = changes_pwd_oldpwd_values(all);
	if (error == 1)
		return (1);
	return (0);
}

int	make_cd(t_shell_command *shell_node, t_all *all)
{
  char *destination;
	int	error;

	make_dup(shell_node);
  if (shell_node->command_info->next != NULL)
	{
	  destination = shell_node->command_info->next->valeur;
		if (destination[0] == '~' && destination[1] == '\0')
		{
			error = make_cd_home(shell_node, all);
			if (error == 1)
				return (1);
			return (0);
		}
		else
		{
			if (cd_to_path(shell_node, all) == 1)
				return (1);
		}
	}
	else
	{
		make_cd_home(shell_node, all);
	}
	return (0);
}
