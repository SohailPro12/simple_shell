#include "shell.h"

/**
 * _getenv - function
 * @var: parameter
 * Return: value
 */

char *_getenv(char *var)
{
	int i;
	char *dup, *key, *value, *env;

	for (i = 0; environ[i]; i++)
	{
		dup = _strdup(environ[i]);
		key = strtok(dup, "=");

		if (_strcmp(key, var) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(dup);
			return (env);
		}
		free(dup);
		dup = NULL;
	}
	return (NULL);
}
