#include "../../../head.h"

int	changes_pwd_oldpwd_values(t_all *all)
{
	int	index_pwd;
	int	index_oldpwd;
	char	*pwd;
	char	*old_pwd;

	index_pwd = find_index_in_env(all->env, "PWD");
	index_oldpwd = find_index_in_env(all->env, "OLDPWD");
	pwd = take_env_from_index(all, index_pwd);
	if (pwd == NULL)
		return (1);
	old_pwd = take_env_from_index(all, index_oldpwd);
	if (old_pwd == NULL)
		return (1);
	free(all->path_values[index_pwd]);
	all->path_values[index_pwd] = pwd;
	free(all->path_values[index_oldpwd]);
	all->path_values[index_oldpwd] = old_pwd;
	return (0);
}

int	make_cd_home(t_shell_command *shell_node, t_all *all)
{
	int	index;
	char *home_path;
  char  *old;
  int error;
	index = find_index_in_env(all->env, "HOME");
	if (index == -1)
		return (1);
	home_path = take_env_from_index(all, index);
  old = getcwd(NULL, 0);
	error = chdir(home_path);
	if (error == 1)
  {
		free(old);
		free(home_path);
    return (1);
	}
	if (error == -1)
	{
		free(old);
		printf("bash: cd: %s: No such file or directory\n", home_path);
		free(home_path);
		return (0);
	}
	error = add_pwd_oldpwd(old, all->env, 1);
  if (error == 1)
	{
		free(old);
		free(home_path);
		return (1);
	}
	error = add_pwd_oldpwd(home_path, all->env, 0);
	if (error == 1)
	{
		free(old);
		free(home_path);
		return (1);
	}
	error = changes_pwd_oldpwd_values(all);
	if (error == 1)
	{
		free(old);
		free(home_path);
		return (1);
	}
	free(home_path);
	free(old);
  (void)shell_node;
	return (0);
}
