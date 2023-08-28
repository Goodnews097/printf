#include "main.h"

/**
 * get_precision - Calculates the precision for prinet_precision - Calculates the precision for prinet_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the argumentset_precision - Calculates the precision for prinet_precision - Calculates the precision for prin
 * @i: List of arguments to be printed.et_precision - Calculates the precision for prinet_precision - Calculates the precision for prin
 * @list: list of arguments.et_precision - Calculates the precision for prinet_precision - Calculates the precision for prinet_precision - Calculates the precision for prin
 *
 * Return: Precision et_precision - Calculates the precision for prinet_precision - Calculates the precision for prinet_precision - Calculates the precision for prin.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
