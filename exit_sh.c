#include "shell.h"

/**
 * exit_shell - function
 * @command: parameter
 * @exit_status: par stat
 */

void exit_shell(char **command, int exit_status)
{
	int status;

	if (command[1] != NULL)
	{
		status = atoi(command[1]);
		if (status >= 0)
			exit_status = status;
	}
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

/**
 * myAtoi- function
 * @str: parameter
 * Return: value
 */

int myAtoi(const char *str)
{
	int s = 1, b = 0, j = 0;

	while (str[j] == ' ')
		j++;

	if (str[j] == '-' || str[j] == '+')
		s = 1 - 2 * (str[j++] == '-');

	while (str[j] >= '0' && str[j] <= '9')
		b = 10 * b + (str[j++] - '0');

	return (b * s);
}


