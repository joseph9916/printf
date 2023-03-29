#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_percent - print a single % and returns 1
 * Return: 1
 */

int print_percent(void)
{
	_ptchar('%');
	return (1);
}

/**
 * print_normally - prints the % and next character
 * @format: format to use
 * Return: 2
 */

int print_normally(const char *format)
{
	write(1, format, 2);
	return (2);
}

/**
 * print_binary - print a number in binary
 * @n: number to print
 * Return: length printed
 */

int print_binary(int n)
{
	int i = 0, j = 2;

	if (n < 0)
	{
		_ptchar('-');
		n = n * -1;
		i++;
	}
	if (n >= 0 && n < 2)
	{
		_ptchar('0' + n);
		i++;
	}
	else
	{
		while (n / j >= 2)
			j = j * 2;
		while (j >= 2)
		{
			_ptchar('0' + (n / j));
			n = n % j;
			j = j / 2;
			i++;
		}
		_ptchar('0' + (n % j));
	}
	return (1);
}
