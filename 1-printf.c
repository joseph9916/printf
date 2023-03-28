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
