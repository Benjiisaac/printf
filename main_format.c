#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;
	int i;
	char c;
	char *s;

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = (char) va_arg(args, int);
					len += write(1, &c, sizeof(char));
					break;
				case 's':
					s = va_arg(args, char*);
					len += write(1, s, strlen(s));
					break;
				case '%':
					len += write(1, &format[i], sizeof(char));
					break;
				default:
					break;
			}
		}
		else
		{
			len += write(1, &format[i], sizeof(char));
		}
	}
	va_end(args);
	return (len);
}
