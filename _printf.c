#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function _printf - Printf function_printf - Printf function_printf - Printf function_printf - Printf function
 * @format: format._printf - Printf function_printf - Printf function_printf - Printf function_printf - Printf function
 * Return: Printed chars._printf - Printf function_printf - Printf function_printf - Printf function
 */
int _printf(const char *format, ...)
{
	int oppy, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (oppy = 0; format && format[oppy] != '\0'; oppy++)
	{
		if (format[oppy] != '%')
		{
			buffer[buff_ind++] = format[oppy];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[oppy], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &oppy);
			width = get_width(format, &oppy, list);
			precision = get_precision(format, &oppy, list);
			size = get_size(format, &oppy);
			++oppy;
			printed = handle_print(format, &oppy, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it Prints the contents of the buffer if it Prints the contents of the buffer if it exist
 * @buffer: Array of Prints the contents of the buffer if itPrints the contents of the buffer if it  chars
 * @buff_ind: Index Prints the contents of the buffer if itPrints the contents of the buffer if it at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
