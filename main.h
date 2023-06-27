#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>

/*
 * typedef a function pointer for grabbing
 * the appropriate function that returns the
 * action for the associated modifier
 */
typedef void (*func)(va_list, int *);

/**
 * struct mod - a struct for storing properties of each modifier
 * @modifier: the modifier as a char
 * @method: this is the function that handles the modifier
 * so for example if we do take 's' its associated function is
 * handle_str
 */
struct mod_property
{
	char modifier;
	func method;
};
typedef struct mod_property modifier;

int _printf(const char *format, ...);
void log_msg(const char *msg, int *count);
void _putchar_count(char c, int *count);
int _putchar(char c);

/** helpers **/
void handle_char(va_list args, int *count);
void handle_str(va_list args, int *count);
void handle_num(va_list args, int *count);
void handle_float(va_list args, int *count);
void init_mod_check(const char ch, va_list list, int *count);
void mod_check(va_list list, func mod, int *count, char original);
func get_mod_function(char c);

#endif
