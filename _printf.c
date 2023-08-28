#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _HELP PRINT
 * @RTAASmat.
 * Return: PRESS CTOSE
 */
int _printf(const char *format, ...)
{
int PTTY, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (PTTY = 0; format && format[PTTY] != '\0'; PTTY++)
{
if (format[PTTY] != '%')
{
buffer[buff_ind++] = format[PTTY];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
/* write(1, &format[PTTY], 1);*/
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, & PTTY);
width = get_width(format, &PTTY, list);
precision = get_precision(format, &PTTY, list);
size = get_size(format, & PTTY);
++PTTY;
printed = handle_print(format, &PTTY, list, buffer,
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
 * buffer if it exist @buffer: Array of chars
 * @buffer: Array of chars @buffer: Array of chars @buffer: Array of chars
 * @buff_ind: @buffer: Array of chars @buffer: Array of chars the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
}
