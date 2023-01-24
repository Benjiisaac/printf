#include <unistd.h>
#include <stdarg.h>

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

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i]);
			{
				case 'c';
					len += write(1, &va_arg(args, int), 1);
					break;
				case 's';
					en += write(1, va_arg(args, char*), strlen(va_arg(args, char*)));
					break;
				case '%';
					len += write(1, &format[i], 1);
					break;
				default:
					break;
			}
		}
		else
		{
			len += write(1, &format[i], 1);
		}
	}
	va_end(args);
	return (len);
}
