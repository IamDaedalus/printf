#include "main.h"
#include <stdarg.h>

/**
 * mod_check - checks if the func returns an actual function pointer
 * @args: the variadic list of functions that we pass to associataed methods
 * @mod: the function pointer data type variable
 * @count: a pointer to the original printf count
 */
void mod_check(va_list args, func mod, int *count)
{
	if (mod)
		mod(args, count);
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
	mod_check(list, mod, count);

}
