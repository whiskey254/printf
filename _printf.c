#include"main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/**
 * printf function that supports basic format specifiers.
 *
 * @param format The format string containing format specifiers.
 * @param ... Variable arguments corresponding to the format specifiers.
 * @return The total number of characters printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i, s_count, count = 0;
	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			my_putchar(format[i]);
		}
		else if (format[i + 1] == 'c')
		{
			my_putchar(va_arg(args, int));
			i++;
		}
		else if (format[i + 1] == 's')
		{
			const char *str = va_arg(args, const char *);
			s_count = my_puts(str);
			i++;
			count += s_count;
		}
		else if (format[i + 1] == '%')
		{
			my_putchar('%');
			i++;
			count++;
		}
	}

	va_end(args);
	return count;
}

/**
 * My puts function that prints a string and returns its length.
 *
 * @param c The input string.
 * @return The length of the string.
 */
int my_puts(const char *c)
{
	int count = 0;

	if (c)
	{
		for (count = 0; c[count] != '\0'; count++)
		{
			my_putchar(c[count]);
		}
	}
	return count;
}

/**
 * Custom putchar function that prints a character.
 *
 * @param c The character to be printed.
 */
void my_putchar(char c)
{
	putchar(c);
}
