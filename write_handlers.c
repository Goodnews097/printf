#include "main.h"

/***********************ddssdss** WRITE HANDLE *************************/
/**
 * handle_write_char - Prints a string
 * @c: char types.handle_write_char - Prints a stringhandle_write_char - Prints a string
 * @buffer: Buffer array to handle prinhandle_write_char - Prints a stringhandle_write_char - Prints a stringt
 * @flags:  Calculates active flags. handle_write_char - Prints a stringhandle_write_char - Prints a string
 * @width: get width.handle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @precision: precision specifier
 * @size: Size specifier handle_write_char - Prints a stringhandle_write_char - Prints a string
 *
 * Return: Number of chars printed. handle_write_char - Prints a stringhandle_write_char - Prints a string
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/********************handle_write_char - Prints a string***** WRITE NUMBER *************************/
/**
 * write_number - Prints a string handle_write_char - Prints a string
 * @is_negative: Lista of arguments handle_write_char - Prints a string
 * @ind: char types. handle_write_char - Prints a string
 * @buffer: Buffer array to handle printhandle_write_char - Prints a string
 * @flags:  Calculates active flagshandle_write_char - Prints a string
 * @width: get width. handle_write_char - Prints a string
 * @precision: precision specifierhandle_write_char - Prints a string
 * @size: Size specifierhandle_write_char - Prints a string
 *
 * Return: Number of chars printed.handle_write_char - Prints a string
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_num -handle_write_char - Prints a stringhandle_write_char - Prints a string Write ahandle_write_char - Prints a stringhandle_write_char - Prints a string number using a bufffer
 * @ind: Index athandle_write_char - Prints a stringhandle_write_char - Prints a string which the number starts on the buffer
 * @buffer: Buffer handle_write_char - Prints a stringhandle_write_char - Prints a string
 * @flags: Flags handle_write_char - Prints a stringhandle_write_char - Prints a string
 * @width: widthhandle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @prec: Precision handle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string specifier
 * @length: Number lengthhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @padd: Pading charhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @extra_c: Extra char handle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - Writes an unsigned number handle_write_char - Prints a stringhandle_write_char - Prints a string
 * @is_negative: Number indicating if the num is negativehandle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @ind: Index at which the number starts in the bufferhandle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @buffer: Array of charshandle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @flags: Flags specifiershandle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @width: Width specifierhandle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @precision: Precision specifierhandle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @size: Size specifier  handle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 *
 * Return: Number of written chars.handle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Write a memory address handle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @buffer: Arrays of chars handle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @ind: Index at which the number starts in the buffer handle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @length: Length of number handle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @width: Width specifier handle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @flags: Flags specifierhandle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @padd: Char representing the padding handle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @extra_c: Char representing extra char handle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 * @padd_start: Index at which padding should start handle_write_char - Prints a stringhandle_write_char - Prints a stringhandle_write_char - Prints a string
 *
 * Return: Number of written chars.handle_write_char - Prints a stringhandle_write_char - Prints a string
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
