#include "shell.h"

/**
 * readinput - read line
 * Return: char pointer
 */

char *readinput(void)
{
	char *buff = NULL;
	size_t longeur = 0;
	ssize_t n_reads;

	if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, "$ ", 2);
	n_reads = getline(&buff, &len, stdin);
	if (n_reads == -1)
	{
		free(buff);
		return (NULL);
	}
	return (buff);
}
