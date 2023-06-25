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

/**
 * handle_str - handles %s
 * @args: the variadic args
 */
void handle_str(va_list args)
{
	char *s;

	s = va_arg(args, char *);
	while (*s)
	{
		_putchar(*s);
		s++;
	}
}

/**
 * handle_char - handles %c
 * @args: the variadic args
 */
void handle_char(va_list args)
{
	_putchar(va_arg(args, int));
}
