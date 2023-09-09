#include "shell.h"

/**
 * tokenizer - function
 * @line: parameter
 * Return: value
 */

char **tokenizer(char *line)
{
	char *token = NULL, delim[] = " \t\n", *dup = NULL;
	char **command = NULL;
	int c = 0, i = 0;

	if (!line)
		return (NULL);

	dup = _strdup(line);
	token = strtok(dup, delim);
	if (token == NULL)
	{
		free(dup);
		dup = NULL;
		free(line);
		line = NULL;
		return (NULL);
	}
	while (token)
	{
		c++;
		token = strtok(NULL, delim);
	}
	free(dup);
	dup = NULL;
	command = malloc(sizeof(char *)*(c + 1));
	if (!command)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	token = strtok(line, delim);
	while (token)
	{
		command[i++] = _strdup(token);
		token = strtok(NULL, delim);
	}
	free(line), line = NULL;
	command[i] = NULL;
	return (command);
}
