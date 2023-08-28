#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**

 format AM TERRIBLE IN ALL OF THIS 
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int POS, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (POS = 0; format && format[POS] != '\0'; POS++)
	{
		if (format[POS] != '%')
		{
			buffer[buff_ind++] = format[POS];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &POS);
			width = get_width(format, &POS, list);
			precision = get_precision(format, &POS, list);
			size = get_size(format, &POS);
			++POS;
			printed = handle_print(format, &POS, list, buffer,
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
 * print_buffer - Prints the contents of theINDIGINIOUSr if it e***/
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
