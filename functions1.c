#include "main.h"

/********************print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower ***** PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer arraprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower y to handle print
 * @flags:  Calculates print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower flags
 * @width: get width
 * @precision: Precisioprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower n specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower MBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @types: Lista of arguments print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @buffer: Buffer array to handle printprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @flags:  Calculates active flags print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @width: get widthprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @precision: Precision specification print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @size: Size specifier print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * Return: Number of chars printedprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNEprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower D NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation print_hexa - Prints a hexadecimal number in lower 
 * @types: Lista of argumentsprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @buffer: Buffer array to handle printprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @flags:  Calculates active flags print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @width: get width print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @precision: Precision specificationprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @size: Size specifierprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * Return: Number of chars printed print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBEprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower R IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notationprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @types: Lista of arguments print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @buffer: Buffer array to handle print print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @flags:  Calculates active flagsprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @width: get width print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @precision: Precision specification print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @size: Size specifier print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * Return: Number of chars printed print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWEprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower R OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of argumentsprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @map_to: Array of values to map the number to print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @buffer: Buffer array to handle printprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @flags:  Calculates active flags print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @flag_ch: Calculates active flags print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @width: get width print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @precision: Precision specification print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @size: Size specifier print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * @size: Size specificationprint_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 * Return: Number of chars printed print_hexa - Prints a hexadecimal number in lower print_hexa - Prints a hexadecimal number in lower 
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
