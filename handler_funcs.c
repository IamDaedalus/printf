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

/**
 * handle_num - handles both %i and %d
 * @args: the variadic args
 */
void handle_num(va_list args)
{
	int num = va_arg(args, int), i = 0;
	/*
	 * you can use int or char if you want
	 * 10 is because int_max is exactly 10 digits minus the sign
	 */
	char arr[10];

	/*
	 * check if the number is less than or equal to zero and perform
	 * necessary operations
	 */
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	if (num == 0)
	{
		_putchar(num);
		return;
	}

	/*
	 * this basically stores the last digit to the array above
	 * and converts it to an int
	 */
	while (num != 0)
	{
		arr[i] = '0' + (num % 10); /* conversion to number is here */
		/*_putchar('0' + (num % 10));*/
		num /= 10;
		i++;
	}

	/* print the array from back to front */
	while (i > 0)
		_putchar(arr[--i]);
}

