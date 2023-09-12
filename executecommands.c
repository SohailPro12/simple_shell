#include "shell.h"

/**
 * execute_command - function
 * @command: parameter
 * @argv: parameter
 * @idx: index
 * Return: Value
 */

int execute_command(char **command, char **argv, int idx)
{
	pid_t pid;
	int status;
	char *full_command;
	static int last_status;

	if (_strcmp(command[0], "env") == 0)
	{
		_printenv(environ);
		free_arr(command);
		return (0);
	}

	if (_strcmp(command[0], "exit") == 0)
		exit_shell(command, last_status);

	full_command = search_path(command[0]);
	if (!full_command)
	{
		printerror(argv[0], command[0], idx);
		free_arr(command);
		return (127);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(full_command, command, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		last_status = WEXITSTATUS(status);
		free(full_command);
		full_command = NULL;
		free_arr(command);
	}
	return (last_status);
}
/**
 * printerror - fuc
 * @shellname: name
 * @cmd: cmd
 * @idx: index
 */

void printerror(char *shellname, char *cmd, int idx)
{
	char *index, notfoundmess[] = ": not found\n";

	index = _iatoi(idx);

	write(STDERR_FILENO, shellname, _strlen(shellname));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, notfoundmess, _strlen(notfoundmess));

	free(index);
}
