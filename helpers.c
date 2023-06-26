#include "main.h"
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
	};

	/* the length of th array */
	modifiers_len = sizeof(modifiers) / sizeof(modifiers[0]);
	while (i < modifiers_len)
	{
		if (modifiers[i].modifier == c)
			return (modifiers[i].method);

		i++;
	}

	return (NULL);
}

/**
 * handle_str - handles %s
 * @args: the variadic args
 * @count: this is a pointer to the original count variable in _printf
 */
void handle_str(va_list args, int *count)
{
	char *s;

	s = va_arg(args, char *);
	while (*s)
	{
		_putchar(*s);
		s++;
		(*count) += 1;
	}
}

/**
 * handle_char - handles %c
 * @args: the variadic args
 * @count: this is a pointer to the original count var in _printf
 */
void handle_char(va_list args, int *count)
{
	_putchar((char)va_arg(args, int));
	(*count) += 1;
}

/**
 * handle_num - handles both %i and %d
 * @args: the variadic args
 * @count: this is a pointer to the original count var in _printf
 */
void handle_num(va_list args, int *count)
{
	int num = va_arg(args, int);
	char arr[10];
	int i = 0;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	do
	{
		arr[i++] = '0' + (num % 10);
		num /= 10;
	} while (num);

	for (i--; i >= 0; i--)
	{
		_putchar(arr[i]);
		(*count) += 1;
	}
}
