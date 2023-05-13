#include "shell.h"



/**
 * is_delim - checks if a character is a separator
 * @c: character check
 * @delim: string separator
 *
 * Return: 0 on false and 1 on true
 */
int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1); /* Return 1 if a match is found */
		delim++;
	}
	return (0); /* Return 0 if no match is found */
}
/**
 * interactive - checks if shell is running in interactive mode
 * @info: this points to the struct pointer
 *
 * Return: this will return 1 on a success and a 0 if not so
 */
int interactive(info_t *info)
{
	/* Check if the standard input is a terminal and */
     /* info->readfd is less than or equal to 2 */
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * _isalpha - checks if a character is alphabetic
 * @c: checker
 *
 * Return: 1 for pass and 0 for fail
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}

/**
 * _atoi - this is going to convert a string into an integer
 * @s: conversion string
 *
 * Return: sends the converted string, pass in 0 if their is no string
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (unsigned int)(s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = (int)result;

	return (output);
}







