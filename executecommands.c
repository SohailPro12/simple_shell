#include "shell.h"

/**
 * execute_command - function
 * @command: parameter
 * @argv: parameter
 * Return: Value
 */

int execute_command(char **command, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			free_arr(command);
			exit(0);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free_arr(command);
	}
	return (WEXITSTATUS(status));
}
