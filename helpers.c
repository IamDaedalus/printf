#include "main.h"
/**
 * mod_check - checks that the mod is returning something other than NULL
 * @list: the variadic args
 * @mod: the func to check
 * I wrote this function because I found myself doing the same checks over
 * and over again so this just encapsulates everything in one
 */
void mod_check(va_list list, func mod)
{
	/* check if the mod has returned a function */
	if (mod)
	{
		/* this just a function pointer that returns the appropriate function*/
		mod(list);
	}
}

/**
 * init_mod_check - fetch the appropriate function for the modifier ch
 * @ch: the modifier as a char
 * @list: the variadic args
 * I wrote this because I found writing switch statements for each modifier
 * a chore and bothersome so this handles everything
 */
void init_mod_check(const char ch, va_list list)
{
	func mod;

	mod = get_mod_function(ch);
	mod_check(list, mod);
}

