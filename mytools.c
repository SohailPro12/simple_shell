#include "shell.h"

/**
 * _strdup - function
 * @str: parameter
 * Return: value
 */

char *_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;

	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		ptr[i] = str[i];

	return (ptr);
}

/**
 * _strcmp - function
 * @s1: parameter
 * @s2: parameter
 * Return: Value
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 < *s2)
			return (-1);
		else if (*s1 > *s2)
			return (1);

		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	else if (*s1 == '\0')
		return (-1);
	else
		return (1);
}

/**
 * _strcpy - function
 * @dest: parameter
 * @src: parameter
 * Return: Value
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strcat - function
 * @dest: parameter
 * @src: parameter
 * Return: Value
 */

char *_strcat(char *dest, char *src)
{
	char *result = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (result);
}
/**
 * _strlen - function
 * @string: parameter
 * Return: value
 */

int _strlen(char *string)
{
	int length = 0;

	while (*string != '\0')
	{
		length++;
		string++;
	}

	return (length);
}

