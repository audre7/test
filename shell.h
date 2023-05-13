#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>

/**
 * struct info_s - Struct to hold information for the shell
 * @argv: Null-terminated array of strings
 * @readfd: File descriptor for reading
 * @status: Status of the previous command
 * @err_num: Error number
 */
typedef struct info_s
{
	char **argv;
	int readfd;
	int status;
	int err_num;
} info_t;

int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);
int _myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);



#endif /* SHELL_H */
