/* Utility functions */
#include "main.h"

/**
 * _write_char - prints a single character to the screen
 * @c: the character to print
 *
 * Return: On success 1
 */
int _write_char(const char c)
{
	/* ssize write(int fd, const void *buf, size_t nbytes); */
	/* fd options: 0 - stdin, 1 - stdout, 2 - stderr */
	/* buf - buffer to write from. If it is a string, then input address */
	/* of that string. If it is a single character, then input address of */
	/* the character. */

	write(1, &c, 1);

	return (1);
}

/**
 * _write_string - prints a string to the screen
 * @str: the string to print
 *
 * Return: On success, the length of the string
 */
int _write_string(const char *str)
{
	int counter = 0;

	for (counter = 0; str[counter]; counter++)
		write(1, &str[counter], 1);

	return (counter);
}

/**
 * _write_decimal - prints a decimal number to the screen
 * @d: the decimal to print
 *
 * Descriptio: This is uses a recursive function.
 * Return: The number of digits in the number
 */
int _write_decimal(long d)
{
	int counter = 0;
	char _negative_sign = '-';

	if (d < 0)
	{
		write(1, &_negative_sign, 1);
		counter++;
		d = (-1) * d;
	}
	if ((d % 10 == 0) && d < 10)
	{
		return (1);
	}
	else
	{
		counter = 1 + _write_decimal((d / 10));
		d = (d % 10) + '0';
		write(1, &d, 1);
	}
	return (counter);
}


/**
 * specifiers - prints items in list based on specifiers
 * @format: the format string to work on
 * @pos: the position to start from
 * @x_list: the list to pick items from
 * @counter: the number of characters printed
 *
 * Description: uses a va_list varible from another function
 * Return: void
 */
void specifiers(const char *format, int *pos, va_list *x_list, int *counter)
{
	char my_char = 0;
	int my_int = 0;
	char *my_string = 0;

	*(pos) += 1; /* get to the next character */
	my_char = format[(*pos)];
	switch (my_char)
	{
	case 'c':
		my_char = va_arg((*x_list), int);
		(*counter) += _write_char(my_char);
		break;
	case 's':
		my_string = va_arg((*x_list), char *);
		(*counter) += _write_string(my_string);
		break;
	case '%':
		(*counter) += _write_char('%');
		break;
	case 'd':
		my_int = va_arg((*x_list), int);
		(*counter) += _write_decimal(my_int);
		break;
	}
}
