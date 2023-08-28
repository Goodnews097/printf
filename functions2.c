#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Priint_rot13string - Print a string in rot13int_rot13string - Print a string in rot13nts the value of a pointer variable
 * @types: List a of argint_rot13string - Print a string in rot13int_rot13string - Print a string in rot13uments
 * @buffer: Buffer int_rot13string - Print a string in rot13 array to handle print
 * @flags:  Cint_rot13string - Print a string in rot13int_rot13string - Print a string in rot13alculates active flags
 * @width: get int_rot13string - Print a string in rot13int_rot13string - Print a string in rot13 width
 * @precision: int_rot13string - Print a string in rot13int_rot13string - Print a string in rot13 Precision specification
 * @size: Size int_rot13string - Print a string in rot13int_rot13string - Print a string in rot13specifier
 * Return: Number of chint_rot13string - Print a string in rot13int_rot13string - Print a string in rot13ars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/************************* PRINT int_rot13string - Print a string in rot13int_rot13string - Print a string in rot13 NON PRINTABLE *************************/
/**
 * print_non_printable - Printsint_rot13string - Print a string in rot13int_rot13string - Print a string in rot13 ascii codes in hexa of non printable chars
 * @types: Lista of argumentsint_rot13string - Print a string in rot13int_rot13string - Print a string in rot13
 * @buffer: Buffer array to int_rot13string - Print a string in rot13int_rot13string - Print a string in rot13 handle print
 * @flags:  Calculates aint_rot13string - Print a string in rot13int_rot13string - Print a string in rot13 ctive flags
 * @width: get width int_rot13string - Print a string in rot13int_rot13string - Print a string in rot13
 * @precision: Precision int_rot13string - Print a string in rot13int_rot13string - Print a string in rot13int_rot13string - Print a string in rot13 specification
 * @size: Size specifier int_rot13string - Print a string in rot13int_rot13string - Print a string in rot13
 * Return: Number of charint_rot13string - Print a string in rot13int_rot13string - Print a string in rot13s printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/************************* PRint_rot13string - Print a string in rot13int_rot13string - Print a string in rot13INT REVERSE *************************/
/**
 * print_reverse - int_rot13string - Print a string in rot13int_rot13string - Print a string in rot13 Prints reverse string.
 * @types: Lista int_rot13string - Print a string in rot13int_rot13string - Print a string in rot13of arguments
 * @buffer: Buffer int_rot13string - Print a string in rot13int_rot13string - Print a string in rot13array to handle print
 * @flags:  Calculint_rot13string - Print a string in rot13int_rot13string - Print a string in rot13int_rot13string - Print a string in rot13ates active flags
 * @width: get width
 * @precisionint_rot13string - Print a string in rot13int_rot13string - Print a string in rot13: Precision specification
 * @size: Sizint_rot13string - Print a string in rot13int_rot13string - Print a string in rot13e specifier
 * Return: Numbers oint_rot13string - Print a string in rot13int_rot13string - Print a string in rot13f chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/************************* PRINT int_rot13string - Print a string in rot13int_rot13string - Print a string in rot13 A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a int_rot13string - Print a string in rot13int_rot13string - Print a string in rot13 string in rot13.
 * @types: Lista of arguments int_rot13string - Print a string in rot13
 * @buffer: Buffer array to haint_rot13string - Print a string in rot13ndle print
 * @flags:  Calculates active flags
 * @width: get width int_rot13string - Print a string in rot13int_rot13string - Print a string in rot13
 * @precision: Precisionint_rot13string - Print a string in rot13int_rot13string - Print a string in rot13 specification
 * @size: Size specifierint_rot13string - Print a string in rot13int_rot13string - Print a string in rot13
 * Return: Numbers of chars int_rot13string - Print a string in rot13int_rot13string - Print a string in rot13printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
