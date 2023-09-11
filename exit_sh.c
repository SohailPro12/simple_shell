#include "shell.h"

/**
 * _exitshell - function
 * @cmd: parameter
 */

void _exitshell(char **cmd)
{
	free_arr(cmd);
	exit(EXIT_SUCCESS);
}
