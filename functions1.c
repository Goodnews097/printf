#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned numberprint_unsigned - Prints an unsigned number print_unsigned - Prints an unsigned number
 * @types: List a of arguments print_unsigned - Prints an unsigned number print_unsigned - Prints an unsigned number
 * @buffer: Buffer array to handle printprint_unsigned - Prints an unsigned number
 * @flags:  Calculates active flags print_unsigned - Prints an unsigned number
 * @width: get width print_unsigned - Prints an unsigned number print_unsigned - Prints an unsigned number
 * @precision: Precision specification print_unsigned - Prints an unsigned number
 * @size: Size specifier print_unsigned - Prints an unsigned number print_unsigned - Prints an unsigned number
 * Return: Number of chars printed.print_unsigned - Prints an unsigned number
 */

int print_unsigned(va_list types, char buffer[],
int flagss, int widthss, int precisionss, int sizess)
{
int BD = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[BD--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[BD--] = (num % 10) + '0';
num /= 10;
}
BD++;
return (write_unsgnd(0, BD, buffer, flagss, widthss, precisionss, sizess));
}
/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation print_octal - Prints an unsigned number in octal notation print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments print_octal - Prints an unsigned number in octal notation print_octal - Prints an unsigned number in octal notation print_octal - Prints an unsigned number in octal notation
 * @buffer: Buffer array to handle print print_octal - Prints an unsigned number in octal notation
 * @flags:  Calculates active flags print_octal - Prints an unsigned number in octal notation
 * @width: get width print_octal - Prints an unsigned number in octal notation print_octal - Prints an unsigned number in octal notation
 * @precision: Precision specification print_octal - Prints an unsigned number in octal notation print_octal - Prints an unsigned number in octal notation
 * @size: Size specifier print_octal - Prints an unsigned number in octal notation
 * Return: Number of chars printed print_octal - Prints an unsigned number in octal notation print_octal - Prints an unsigned number in octal notation
 */
int print_octal(va_list types, char buffer[],
int flagss, int widthss, int precisionss, int sizess)
{
int BD = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(widthss);
num = convert_size_unsgnd(num, sizess);
if (num == 0)
buffer[BD--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[BD--] = (num % 8) + '0';
num /= 8;
}
if (flags & F_HASH && init_num != 0)
buffer[BD--] = '0';
BD++;
return (write_unsgnd(0, BD, buffer, flagss, widthss, precisionss, sizess));
}
/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments @types: Lista of arguments@types: Lista of arguments@types: Lista of arguments
 * @buffer: Buffer array to handle print @types: Lista of arguments@types: Lista of arguments@types: Lista of arguments@types: Lista of arguments
 * @flags:  Calculates active flags@types: Lista of arguments@types: Lista of arguments@types: Lista of arguments@types: Lista of arguments
 * @width: get width @types: Lista of arguments@types: Lista of arguments@types: Lista of arguments@types: Lista of arguments@types: Lista of arguments
 * @precision: Precision specification @types: Lista of arguments@types: Lista of arguments@types: Lista of arguments@types: Lista of arguments@types: Lista of arguments
 * @size: Size specifier @types: Lista of arguments@types: Lista of arguments@types: Lista of arguments@types: Lista of arguments
 * Return: Number of chars printed @types: Lista of arguments@types: Lista of arguments@types: Lista of arguments
 */
int print_hexadecimal(va_list types, char buffer[],
int flagss, int widthss, int precisionss, int sizess)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', widthss, precisionss, sizess));
}
/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments print_hexa_upper - Prints an unsigned number in upper hexadecimal notationprint_hexa_upper - Prints an unsigned number in upper hexadecimal notationprint_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @buffer: Buffer array to handle printprint_hexa_upper - Prints an unsigned number in upper hexadecimal notationprint_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @flags:  Calculates active flags print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @width: get width print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @precision: Precision specification print_hexa_upper - Prints an unsigned number in upper hexadecimal notation print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @size: Size specifierprint_hexa_upper - Prints an unsigned number in upper hexadecimal notationprint_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
int flagss, int widthss, int precisionss, int sizess)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', widthss, precisionss, sizess));
}
/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments print_hexa - Prints a hexadecimal number in lower or upper
 * @map_to: Array of values to map the number to print_hexa - Prints a hexadecimal number in lower or upper
 * @buffer: Buffer array to handle printprint_hexa - Prints a hexadecimal number in lower or upper
 * @flags:  Calculates active flagsprint_hexa - Prints a hexadecimal number in lower or upper
 * @flag_ch: Calculates active flags print_hexa - Prints a hexadecimal number in lower or upper
 * @width: get widthprint_hexa - Prints a hexadecimal number in lower or upper
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
int flagss, char flag_ch, int widthss, int precisionss, int sizess)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(widthss);
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
