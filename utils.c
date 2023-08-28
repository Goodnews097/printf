#include "main.h"

/**
 * is_printable - Evaluates if a char is printable rintable - Evaluates if a char is printablerintable - Evaluates if a char is printablerintable - Evaluates if a char is printable
 * @c: Char to be evaluated. rintable - Evaluates if a char is printablerintable - Evaluates if a char is printable
 *
 * Return: 1 if c is printable, 0 otherwiserintable - Evaluates if a char is printablerintable - Evaluates if a char is printablerintable - Evaluates if a char is printable
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer rintable - Evaluates if a char is printablerintable - Evaluates if a char is printablerintable - Evaluates if a char is printable
 * @buffer: Array of chars.rintable - Evaluates if a char is printablerintable - Evaluates if a char is printable
 * @i: Index at which to start appending.rintable - Evaluates if a char is printablerintable - Evaluates if a char is printable
 * @ascii_code: ASSCI CODE.rintable - Evaluates if a char is printablerintable - Evaluates if a char is printablerintable - Evaluates if a char is printable
 * Return: Always 3 rintable - Evaluates if a char is printablerintable - Evaluates if a char is printable
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit rintable - Evaluates if a char is printable
 * @c: Char to be evaluated rintable - Evaluates if a char is printable
 *
 * Return: 1 if c is a digit, 0 otherwise rintable - Evaluates if a char is printable
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Castsrintable - Evaluates if a char is printablerintable - Evaluates if a char is printable a number to the specified size
 * @num: Number to be casted.rintable - Evaluates if a char is printablerintable - Evaluates if a char is printable
 * @size: Number indicating trintable - Evaluates if a char is printablerintable - Evaluates if a char is printablehe type to be casted.
 *
 * Return: Casted value rintable - Evaluates if a char is printablerintable - Evaluates if a char is printablerintable - Evaluates if a char is printableof num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - rintable - Evaluates if a char is printablerintable - Evaluates if a char is printablerintable - Evaluates if a char is printableCasts a number to the specified size
 * @num: Number to be castedrintable - Evaluates if a char is printablerintable - Evaluates if a char is printablerintable - Evaluates if a char is printable
 * @size: Number indicating the typerintable - Evaluates if a char is printablerintable - Evaluates if a char is printablerintable - Evaluates if a char is printable to be casted
 *
 * Return: Casted value of num rintable - Evaluates if a char is printablerintable - Evaluates if a char is printable
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
