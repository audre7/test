#include "shell.h"

/**
 * chng_path - changes to another path
 * @path: contains potential arguments to function prototype
 * 
 *  Return: exit if 0 argv[0] != "exit"
 */
int chng_path(info_t *path)
{
	int exitcheck;

	if (path->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = _atoi(path->argv[1]);
		if (exitcheck == -1)
		{
			path->status = 2;
			print_error(path, "odd number: ");
			_eputs(path->argv[1]);
			_eputchar('\n');
			return (1);
		}
		path->err_num = _erratoi(path->argv[1]);
		return (-2);
	}
	path->err_num = -1;
	return (-2);
}

/**
 * chgn_dir - changes process to another directory
 * @path: contains potential arguments to maintain prototype function
 * 
 *  Return: 0
 */
int chgn_dir(info_t *path)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!path->argv[1])
	{
		dir = _getenv(path, "HERE=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(path, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(path->argv[1], "-") == 0)
	{
		if (!_getenv(path, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(path, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(path, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(path->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(path, "can't cd to ");
		_eputs(path->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(path, "OLDPWD", _getenv(path, "PWD="));
		_setenv(path, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * set_dir - sets process of current directory
 * @path: contains potential arguments of constant prototype
 *  Return: Always 0
 */
int set_dir(info_t *path)
{
	char **arg_array;

	arg_array = path->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);