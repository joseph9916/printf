#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * print_number - Takes a number as input and prints it with putchar
 * @n: Input integer
 * Return: 0 Always (Success)
 */

int print_decimal_number(int n)
{
	/*AN interger to get the integer division of i*/
	int i = 0, j = 10;
	
	if (n < 0)
	{
		_ptchar('-');
		n = n * -1;
		i++;
	}
	if (n >= 0 && n < 10)
	{
		_ptchar('0' + n);
		i++;
	}
	else
	{
		while (n / j >= 10)
			j = j * 10;
		while (j >= 10)
		{
			_ptchar('0' + (n / j));
			n = n % j;
			j = j / 10;
			i++;
		}
		_ptchar('0' + (n % 10));
		i++;
	}
	return (i);
}

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
			if (format[1] == 'c') /*(*(format + 1)*/
				i = print_char(va_arg(ap, int));
			else if (format[1] == 's')
				i = print_str(va_arg(ap, char *));
			else if (format[1] == 'd')
				i = print_decimal_number(va_arg(ap, int));
			else if (format[1] == '\0')
				return (len);
			else if (format[1] == '%')
				i = print_percent();
			else
				i = print_normally(format);
			format += 2;
			len += i;
		}
	}
	va_end(ap);
	return (len);
}
