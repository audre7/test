#include "shell.h"

/**
 * hist_list - displays history list starting from 0
 * @struct: Structure containing potential arguments
 * 
 *  Return: Always 0
 */
int hist_list(info_t *struct)
{
	print_list(struct->history);
	return (0);
}

/**
 * _alias - sets alias to string
 * @struct: parameter struct
 * @str: string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int _alias(info_t *struct, char *str)
{
	char *p, f;
	int ali;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	f = *p;
	*p = 0;
	ali = delete_node(&(struct->alias),
		get_node(struct->alias, start_node_with(struct->alias, str, -1)));
	*p = f;
	return (ali);
}

/**
 * _alias - points alias to string
 * @struct: structure of the parameter
 * @str: string of the alias
 *
 * Return: Always 0 on success, 1 on error
 */
int _alias(info_t *struct, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (_alias(struct, str));

	_alias(struct, str);
	return (add_node(&(struct->alias), str, 0) == NULL);
}

/**
 * _print - prints the string of the alias
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int _print(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * rep_alias - represents the alias builtin
 * @struct: Structure containing potential arguments of function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *struct)
{
	int w = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (struct->argc == 1)
	{
		node = struct->alias;
		while (node)
		{
			_print(node);
			node = node->next;
		}
		return (0);
	}
	for (w = 1; struct->argv[w]; w++)
	{
		p = _strchr(struct->argv[w], '=');
		if (p)
			set_alias(struct, struct->argv[w]);
		else
			_print(node_starts_with(struct->alias, struct->argv[w], '='));
	}

	return (0);
}