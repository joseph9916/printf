#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * print_char - prints a character and returns the length
 * @c: character
 * Return: 1
 */

int print_char(int c)
{
	_ptchar(c);
	return (1);
}

/**
 * print_str - print a string and returns the length
 * @str: string to print
 * Return: length of string
 */

int print_str(char *str)
{
	int len = 0;

	if (str == NULL)
	{
		free(str);
		return (0);
	}
	while (*str != '\0')
	{
		_ptchar(*str);
		str++;
		len++;
	}
	return (len);
}

/**
 * _printf - prints a string format and returns the length
 * @format: format of character to print
 * Return: length of string
 */

int _printf(const char *format, ...)
{
	int len = 0, i = 0;
	va_list ap;

	va_start(ap, format);
	if (format == NULL)
	{
		return (0);
	}
	while (*format != '\0')
	{
		if (*format != '%')
		{
			_ptchar(*format);
			format++;
			len++;
		}
		else
		{
			/**
			 * if (format[len + 1]  == 'd')
				len = print_decimal_number(format, len, va_arg(ap, int));
				*/
			if (*(format + 1) == 'c')
				i = print_char(va_arg(ap, int));
			if (*(format + 1) == 's')
				i = print_str(va_arg(ap, char *));
			/**
			 * else if (format[len + 1] == 'x')
				len = print_hexadecimal_number(format, len, va_arg(ap, int));
			else if (format[len + 1] == 'X')
				len = print_hexadecimal_number_cap(format, len, va_arg(ap, int));
			else if (format[len + 1] == 'o')
				len = print_octal_number(format, len, va_arg(ap, int));
				*/
			format += 2;
			len += i;
		}
	}
	va_end(ap);
	return (len);
}