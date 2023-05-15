#include "shell.h"

/**
 * exit_shell - Terminates the shell program
 * @info: this contain the valid arguments 
 *
 * Return: info.argv[0] != "exit"
 *         
 */
int exit_shell(info_t *info)
{
    int exit_status;

    if (info->argv[1]) /* If there is an exit argument */
    {
        exit_status = _erratoi(info->argv[1]); /* Convert the exit argument to an integer */
        if (exit_status == -1) /* Check if the exit status is invalid */
        {
            info->status = 2;
            print_error(info, "Invalid exit status: "); /* Print an error message */
            _eputs(info->argv[1]); /* Print the invalid exit status */
            _eputchar('\n'); /* Print a newline character */
            return (1); /* Return 1 to indicate an error */
        }
        info->err_num = _erratoi(info->argv[1]); /* Set the error number to the exit status */
        return (-2); /* Return -2 to indicate a request to exit the shell with a specific status */
    }

    info->err_num = -1; /* Set the error number to -1 to indicate no specific exit status */
    return (-2); /* Return -2 to indicate a request to exit the shell */
}



/**
 * cd - Changes the current directory 
 * @info: this contain the valid arguments 
 *
 * Return: Always 0
 */
int cd(info_t *info)
{
	char *s, *dir, buffer[1024]; /* Declare variables for storing directory information */
	int chdir_ret; /* Variable to store the return value of the chdir function */

	s = getcwd(buffer, sizeof(buffer)); /* Get the current working directory */
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n"); /* Print an error message if getcwd fails */

	if (!info->argv[1]) /* Check if no argument is provided */
	{
		dir = _getenv(info, "HOME="); /* Get the value of the HOME environment variable */
		if (!dir)
			chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/"); /* Change directory to HOME or PWD if HOME is not set */
		else
			chdir_ret = chdir(dir); /* Change directory to HOME */
	}
	else if (_strcmp(info->argv[1], "-") == 0) /* Check if the argument is "-" */
	{
		dir = _getenv(info, "OLDPWD="); /* Get the value of the OLDPWD environment variable */
		if (!dir)
		{
			_puts(s); /* Print the current working directory */
			_putchar('\n'); /* Print a newline character */
			return (1); /* Return 1 to indicate a successful operation */
		}
		_puts(dir); /* Print the value of OLDPWD */
		_putchar('\n'); /* Print a newline character */
		chdir_ret = chdir(dir); /* Change directory to OLDPWD */
	}
	else
	{
		chdir_ret = chdir(info->argv[1]); /* Change directory to the specified argument */
	}

	if (chdir_ret == -1) /* Check if chdir failed */
	{
		print_error(info, "can't cd to "); /* Print an error message */
		_eputs(info->argv[1]); /* Print the argument causing the error */
		_eputchar('\n'); /* Print a newline character */
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD=")); /* Update the value of OLDPWD to the current working directory */
		s = getcwd(buffer, sizeof(buffer)); /* Get the current working directory */
		_setenv(info, "PWD", s); /* Update the value of PWD to the current working directory */
	}

	return (0); /* Return 0 to indicate a successful operation */
}

/**
 * help - provide the help information
 * @info: this will have the arguments as always 
 *
 * Return: Always 0
 */
int help(info_t *info)
{
    char **arg_array = info->argv;

    _puts("Help call works. Function not yet implemented.\n");
    if (*arg_array)
        _puts(*arg_array); /* temp att_unused workaround */
    return (0);
}