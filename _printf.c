#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	va_list list;
	int count = 0, i = 0;

	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++; /* move the iterator to the next letter (the modifier) now */

			/* moved everything here because checking every modifier
			 * would have exceeded the 50line limit for functions
			 */
			init_mod_check(format[i], list);
			i++; /* moves the iterator past the modifier character */
		}
		_putchar(format[i]);
		i++;
		count++;
	}

	va_end(list);

	return (count);
}

