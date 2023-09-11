#include "shell.h"

/**
 * exit_shell - function
 * @command: parameter
 * @exit_status: par stat
 */

void exit_shell(char **command, int exit_status)
{
	free_arr(command);
	exit(exit_status);
}
