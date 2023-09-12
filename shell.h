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

int execute_command(char **command,char** argv, int idx);
char *search_path(char *cmd);
void exit_shell(char **command, int exit_status);
void _printenv(char **command);
size_t _sizecmd(const char *str);
char *_getenv(char *var);
void printerror(char *shellname, char *cmd, int idx);
char *_iatoi(int n);
void reverse_string(char *str, int len);

#endif /* SHELL_H */
