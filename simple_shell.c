#include "shell.h"

/**
 * main - entry point
 * @ac: argc
 * @argv: argv
 * Return: value
 */

int main(int ac, char **argv)
{
	char *buff = NULL;
	char **command = NULL;
	int status = 0, idx = 0;

	(void)ac;

	while (1)
	{
		buff = readinput();

		if (buff == NULL)
		{
			if (isatty(STDIN_FILENO) != 0)
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		idx++;
		command = tokenizer(buff);
		if (command == NULL)
			continue;

		status = execute_command(command, argv, idx);
	}
	return (0);
}
