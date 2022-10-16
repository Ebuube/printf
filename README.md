```
ROLAND OODO AND EBUBE GIDEON
```

# Replicating the printf() fucntion as _printf()

The new function \_printf(), works almost like printf, because it considers
the specifiers (e.g. %d, %c, ...) but does not consider the flags, yet.

Write a function that produces output according to a format.

Prototype: int \_printf(const char \*format, ...);

* Returns: the number of characters printed (excluding the null byte used to end
output to strings)

* write output to stdout, the standard output stream

* format is a character string. The format string is composed of zero or more directives.

See man 3 printf for more detail.

You need to handle the following conversion specifiers:

	- `c`
	- `s`
	- `%`

### NOTE
These were not considered in creating this new function \_printf()

* It doesn't reproduce the buffer handling of the C library printf function

* It doesn't handle the flag characters

* It doesn't handle field width

* It doesn't handle precision

* It doesn't handle the length modifiers
