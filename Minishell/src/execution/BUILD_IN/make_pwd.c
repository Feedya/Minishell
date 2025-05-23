#include "../../head.h"

int	make_pwd(t_shell_command *node)
{
	char *path;
	int	error;

	error = make_dup(node);
	if (error == 1)
		return (1);
	path = getcwd(NULL, 0);
	printf("%s\n", path);
	free(path);
	return (0);
}
