#include "main.h"

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

	va_start(my_list, format);
	for (i = 0; format[i]; i++)
	{
		my_char = format[i];
		switch (my_char)
		{
		case '%':
			specifiers(format, &i, &my_list, &counter);
			break;
		case '\\':
			escapes(format, &i, &counter);
			break;
		default:
			counter += _write_char(my_char);
		}
	}
	va_end(my_list);	/* end of the variable list */

	return (counter);
}
