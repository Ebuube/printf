#ifndef __PRINTF_H_
#define __PRINTF_H_

/* header file used in this program */
#include <stdarg.h>
#include <unistd.h>

int _write_char(const char c);
int _write_string(const char *str);
int _printf(const char *format, ...);
int _write_decimal(long d);
void specifiers(const char *format, int *pos, va_list *x_list, int *counter);

#endif /* __PRINTF_H_ */
