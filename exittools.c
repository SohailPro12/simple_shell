#include "shell.h"

/**
 * write_error_message - fuc
 * @program_name: arg
 * @bad_argument: barg
 */

void write_error_message(char *program_name, char *bad_argument)
{
	char error_message[] = ": 1: exit: Illegal number: ";

	write(2, program_name, _strlen(program_name));
	write(2, error_message, _strlen(error_message));
	write(2, bad_argument, _strlen(bad_argument));
	write(2, "\n", 1);
}

/**
 * is_all_numbers - fuc
 * @str: arg
 * Return: int
 */

int is_all_numbers(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}
