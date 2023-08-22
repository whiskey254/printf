#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current position in the format string
 * @list: List of arguments
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	UNUSED(list);

	if (format[curr_i] == 'r')
	{
		precision = curr_i - (*i + 1);
		*i = curr_i;
	}

	return (precision);
}

