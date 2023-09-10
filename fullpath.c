#include "shell.h"

/**
 * search_path - look for full path
 * @cmd: command
 * Return: char
 */

char *search_path(char *cmd)
{
	char *path = getenv("PATH");
	char *pathcopy = _strdup(path);
	char *dir = strtok(pathcopy, ":");
	char *cmd_path = malloc(PATH_MAX);
	struct stat st;
	char *q;

	while (dir != NULL)
	{
		char *p = cmd_path;

		while (*dir)
			*p++ = *dir++;
		*p++ = '/';
		q = cmd;
		while (*q)
			*p++ = *q++;
		*p = '\0';

		if (stat(cmd_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(pathcopy);
			pathcopy = NULL;
			return (cmd_path);
		}
		dir = strtok(NULL, ":");
	}

	free(pathcopy);
	pathcopy = NULL;
	free(cmd_path);
	return (NULL);
}
