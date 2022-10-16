/* Utility functions */

#include <unistd.h>

/**
 * _write_char - prints a single character to the screen
 * @c: the character to print
 *
 * Return: On success 1
 */
int _write_char(const char c)
{
	/* ssize write(int fd, const void *buf, size_t nbytes);
	 * fd options: 0 - stdin, 1 - stdout, 2 - stderr
	 * buf - buffer to write from. If it is a string, then input address
	 * of that string. If it is a single character, then input address of
	 * the character.
	 */

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

	for(counter = 0; str[counter]; counter++)
		write(1, &str[counter], 1);

	return (counter);
}