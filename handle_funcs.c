#include "main.h"
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>


/**
 * handle_reverse - handles the %r for reversing string
 * @args: the args as a va_list
 * @count: the original printf scan
 */
void handle_reverse(va_list args, int *count)
{
	char *str = va_arg(args, char *);
	/* get range */
	char *start = str;
	char *end = start + strlen(str) - 1; /* -1 for \0 */
	char temp;

	/* reverse */
	while (end > start)
	{
		/* swap */
		temp = *start;
		*start = *end;
		*end = temp;

		/* move */
		++start;
		--end;
	}

	log_msg(start, count);
}


/**
 * handle_rot13 - returns the rot13'd string of input
 * @args: the va_list
 * @count: the count of the original printf
 */
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

