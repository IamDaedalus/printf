#include "main.h"
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>


/**
 * get_mod_function - returns a function pointer to the appropriate
 * function for the modifier c
 * @c: the modifier as a char
 * Return: returns the function pointer to the associated func
 */
func get_mod_function(char c)
{
	int i = 0;
	int modifiers_len = 0;

	modifier modifiers[] = {
		{ 's', handle_str },
		{ 'c', handle_char },
		{ 'd', handle_num },
		{ 'i', handle_num },
		{ '%', handle_char },
		{ 'R', handle_rot13 },
	};

	modifiers_len = sizeof(modifiers) / sizeof(modifiers[0]);
	while (i < modifiers_len)
	{
		if (modifiers[i].modifier == c)
			return (modifiers[i].method);

		i++;
	}

	return (NULL);
}

void handle_rot13(va_list args, int *count)
{
	int i = 0;
	char *s = va_arg(args, char *);

	while (s[i] != '\0')
	{
		if ((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && s[i] <= 'M'))
			_putchar_count(s[i] + 13, count);
		else if ((s[i] >= 'n' && s[i] <= 'z') || (s[i] >= 'N' && s[i] <= 'Z'))
			_putchar_count(s[i] - 13, count);
		else
			_putchar(s[i]);
		i++;
	}
}


/**
 * handle_str - handles %s
 * @args: the variadic args
 * @count: this is a pointer to the original count variable in _printf
 */
void handle_str(va_list args, int *count)
{
	const char *s;

	s = va_arg(args, char *);
	if (!s)
		log_msg("(null)", count);
	else
		log_msg(s, count);
}

/**
 * handle_char - handles %c
 * @args: the variadic args
 * @count: this is a pointer to the original count variable in _printf
 */

void handle_char(va_list args, int *count)
{
	char c = va_arg(args, int);

	_putchar_count(c, count);
}

/**
 * handle_num - handles both %i and %d
 * @args: the variadic args
 * @count: this is a pointer to the original count variable in _printf
 */
void handle_num(va_list args, int *count)
{
	int num = va_arg(args, int), i = 0;

	char arr[10];

	if (num < 0)
	{
		_putchar_count('-', count);

		if (num != INT_MIN)
			num = -num;
		else
		{
			/* print the INT_MIN and exit early */
			log_msg("2147483648", count);
			return;
		}
	}
	if (num == 0 || !num)
	{
		_putchar_count('0', count);
		return;
	}


	/* actual number processing */
	while (num != 0)
	{
		arr[i] = '0' + (num % 10);
		num /= 10;
		i++;
	}

	while (i > 0)
		_putchar_count(arr[--i], count);
}

