#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/*
 * typedef a function pointer for grabbing
 * the appropriate function that returns the
 * action for the associated modifier
 */
typedef void (*func)(va_list);

/**
 * struct mod - a struct for storing properties of each modifier
 * @modifier: the modifier as a char
 * @method: this is the function that handles the modifier
 * so for example if we do take 's' its associated function is
 * handle_str
 */
struct mod
{
	char modifier;
	func method;
};
typedef struct mod modifier;

int _printf(const char *format, ...);
int _putchar(char c);

/** helpers **/
void handle_char(va_list args);
void handle_str(va_list args);
void handle_num(va_list args);
void handle_float(va_list args);
void init_mod_check(const char ch, va_list list);
void mod_check(va_list list, func mod);
func get_mod_function(char c);

#endif
