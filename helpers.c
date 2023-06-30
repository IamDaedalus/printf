#include "main.h"
#include <stdarg.h>


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

/**
 * mod_check - checks if the func returns an actual function pointer
 * @args: the variadic list of functions that we pass to associataed methods
 * @mod: the function pointer data type variable
 * @count: a pointer to the original printf count
 */
void mod_check(va_list args, func mod, int *count, char ch)
{
	if (mod)
		mod(args, count);
	else
	{
		/* hacky way to handle unknown formats but let's do this */
		_putchar_count('%', count);
		_putchar_count(ch, count);
	}
}

/**
 * init_mod_check - initialises modifier checks when called
 * @ch: the modifier as a character
 * @list: the variadic list of functions that we pass to associataed methods
 * @count: a pointer to the original printf count
 */
void init_mod_check(const char ch, va_list list, int *count)
{
	func mod;

	mod = get_mod_function(ch);
	mod_check(list, mod, count, ch);
}

/**
 * log_msg - prints any text fed to it on the screen
 * @msg: the message to prints
 * @count: a pointer to the original printf count
 */
void log_msg(const char *msg, int *count)
{
	if (!msg)
		msg = "(null)";

	while (*msg)
	{
		_putchar_count(*msg, count);
		msg++;
	}
}

/**
 * _putchar_count - prints a character and updates count
 * @c: the character to print
 * @count: a pointer to the original printf count
 * Wrote this to "extend" the original _putchar in case we need it
 */
void _putchar_count(char c, int *count)
{
	_putchar((char)c);
	*count += 1;
}
