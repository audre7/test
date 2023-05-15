#include "shell.h"

/**
 * history -  with line numbers, starting at 0.
 *              
 * @info: Used to maintain Structure containing potential arguments. 
 *  Return: Always 0
 */
int history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * reset_alias - reset alias 
 * @info: struct 
 * @str: the alias 
 *
 * Return: Always 0 on success, 1 on error
 */
int reset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * put - this will put the alias 
 * @info: struct parameter 
 * @str: alias the string 
 *
 * Return: Always 0 on success, 1 on error
 */
int put_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (reset_alias(info, str));

	reset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * write_alias - alias string
 * @node: node alias 
 *
 * Return: Always 0 on success, 1 on error
 */


int write_alias(list_t *node)
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
 * all_alias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int all_alias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			write_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			put_alias(info, info->argv[i]);
		else
			write_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}