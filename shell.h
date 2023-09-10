#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>

extern char **environ;

char *readinput(void);

char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *string);

char **tokenizer(char *line);

void free_arr(char **arr);

int execute_command(char **command,char** argv);
char *search_path(char *cmd);

#endif /* SHELL_H */
