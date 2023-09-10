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
	char *cmd_path;

	if (command[0][0] == '/' || command[0][0] == '.')
		cmd_path = _strdup(command[0]);
	else
	{
		cmd_path = search_path(command[0]);
	}
	if (cmd_path == NULL)
	{
		write(STDERR_FILENO, argv[0], strlen(argv[0]));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, command[0], strlen(command[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		free_arr(command);
		return (127);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd_path, command, environ) == -1)
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
	free(cmd_path);
	return (WEXITSTATUS(status));
}
