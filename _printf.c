#include "main.h"
#include <stdarg.h>	/* for variable list */

/**
 * _printf - a function that produces output according to a format.
 * @format: a string that contains what to print and how to print
 *
 * Description: This function uses a variable list to the specify what to print
 * Return: the number of characters printed to standard output
 */
int _printf(const char *format, ...)
{
	va_list my_list;
	int counter = 0, i = 0;
	char my_char = 0;
	char *my_string = 0;

	va_start(my_list, format);
	for (i = 0; format[i]; i++)
	{
		my_char = format[i];
		if (my_char != '%')
			counter += _write_char(my_char);
		else
		{
			i++; /* get to the next character */
			my_char = format[i];
			switch (my_char)
			{
			case 'c':
				my_char = va_arg(my_list, int);
				counter += _write_char(my_char);
				break;
			case 's':
				my_string = va_arg(my_list, char *);
				counter += _write_string(my_string);
				break;
			case '%':
				counter += _write_char('%');
				break;
			}
		}
	}
	va_end(my_list);	/* end of the variable list */

	return (counter);
}
