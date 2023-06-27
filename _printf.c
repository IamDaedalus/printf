#include <stdarg.h>
#include "main.h"

/**
 * _printf - a mostly 1:1 clone of _printf
 * @format: the text and it's formats
 * Return: returns the count in format
 */

int _printf(const char *format, ...)
{
	va_list list;
	int count = 0, i = 0;

	va_start(list, format);
	if (format)
	{
		while (format[i])
		{
			if (format[i] == '%')
			{
				i++;

				if (format[i] == '%')
					_putchar(format[i]);

				/** find a way to send both % and the format specifier **/
				init_mod_check(format[i], list, &count);
			}
			else
			{
				_putchar(format[i]);
				count++;
			}
			i++;
		}
	}
	else
	{
		/* set count to -1 to indicate nothing */
		count = -1;
	}

	va_end(list);

	return (count);
}
