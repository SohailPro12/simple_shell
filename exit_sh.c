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

/**
 * _printenv - function
 * @command: parameter
 */

void _printenv(char **command)
{
	int i;

	for (i = 0; command[i] != NULL; i++)
	{
		write(1, command[i], _sizecmd(command[i]));
		write(1, "\n", 1);
	}
}

/**
 * _sizecmd - function
 * @str: parameter
 * Return: value
 */

size_t _sizecmd(const char *str)
{
	size_t len = 0;

	while (str[len])
		len++;

	return (len);
}
