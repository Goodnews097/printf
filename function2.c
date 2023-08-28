#include "main.h"
/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments print_pointer - Prints the value of a pointer variable
 * @buffer: Buffer array to handle print print_pointer - Prints the value of a pointer variable
 * @flags:  Calculates active flags print_pointer - Prints the value of a pointer variable
 * @width: get width print_pointer - Prints the value of a pointer variable
 * @precision: Precision specification print_pointer - Prints the value of a pointer variable
 * @size: Size specifier print_pointer - Prints the value of a pointer variable
 * Return: Number of chars printed. print_pointer - Prints the value of a pointer variable
 */
int print_pointer(va_list types, char buffer[],
int flagss, int widths, int precisions, int sizes)
{
char extra_c = 0, padd = ' ';
int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);
UNUSED(widths);
UNUSED(sizes);
if (addrs == NULL)
return (write(1, "NULL", 4));
buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precisions);
num_addrs = (unsigned long)addrs;
while (num_addrs > 0)
{
buffer[ind--] = map_to[num_addrs % 16];
num_addrs /= 16;
length++;
}
if ((flagss & F_ZERO) && !(flagss & F_MINUS))
padd = '0';
if (flagss & F_PLUS)
extra_c = '+', length++;
else if (flagss & F_SPACE)
extra_c = ' ', length++;
ind++;
/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
return (write_pointer(buffer, ind, length,
widths, flagss, padd, extra_c, padd_start));
}
/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of argumentsprint_non_printable - Prints ascii codes in hexa of non printable charsprint_non_printable - Prints ascii codes in hexa of non printable chars
 * @buffer: Buffer array to handle printprint_non_printable - Prints ascii codes in hexa of non printable charsprint_non_printable - Prints ascii codes in hexa of non printable charsprint_non_printable - Prints ascii codes in hexa of non printable chars
 * @flags:  Calculates active flagsprint_non_printable - Prints ascii codes in hexa of non printable chars
 * @width: get widthprint_non_printable - Prints ascii codes in hexa of non printable chars
 * @precision: Precision specificationprint_non_printable - Prints ascii codes in hexa of non printable charsprint_non_printable - Prints ascii codes in hexa of non printable chars
 * @size: Size specifierprint_non_printable - Prints ascii codes in hexa of non printable chars
 * Return: Number of chars printed print_non_printable - Prints ascii codes in hexa of non printable chars
 */
int print_non_printable(va_list types, char buffer[],
int flagss, int widths, int precisions, int sizes)
{
int FC = 0, offset = 0;
char *str = va_arg(types, char *);
UNUSED(flagss);
UNUSED(widths);
UNUSED(precisions);
UNUSED(sizes);
if (str == NULL)
return (write(1, "(null)", 6));
while (str[FC] != '\0')
{
if (is_printable(str[FC]))
buffer[FC + offset] = str[FC];
else
offset += append_hexa_code(str[FC], buffer, FC + offset);
FC++;
}
buffer[FC + offset] = '\0';
return (write(1, buffer, FC + offset));
}
/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.@types: Lista of arguments
 * @types: Lista of arguments@types: Lista of arguments
 * @buffer: Buffer array to handle print@types: Lista of arguments
 * @flags:  Calculates active flags @types: Lista of arguments
 * @width: get width @types: Lista of arguments 
 * @precision: Precision specification @types: Lista of arguments
 * @size: Size specifier@types: Lista of arguments
 * Return: Numbers of chars printed @types: Lista of arguments@types: Lista of arguments@types: Lista of arguments
 */
int print_reverse(va_list types, char buffer[],
int flagss, int widths, int precisions, int sizes)
{
char *str;
int DC, count = 0;
UNUSED(buffer);
UNUSED(flagss);
UNUSED(widths);
UNUSED(sizes);
str = va_arg(types, char *);
if (str == NULL)
{
UNUSED(precisions);
str = ")Null(";
}
for (DC = 0; str[DC]; DC++)
;
for (DC = DC - 1; DC >= 0; DC--)
{
char z = str[DC];
write(1, &z, 1);
count++;
}
return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.print_rot13string - Print a string in rot13.
 * @types: Lista of argumentsprint_rot13string - Print a string in rot13.
 * @buffer: Buffer array to handle printprint_rot13string - Print a string in rot13.
 * @flags:  Calculates active flagsprint_rot13string - Print a string in rot13.
 * @width: get width print_rot13string - Print a string in rot13.
 * @precision: Precision specificationprint_rot13string - Print a string in rot13.
 * @size: Size specifier print_rot13string - Print a string in rot13.
 * Return: Numbers of chars printed print_rot13string - Print a string in rot13.
 */
int print_rot13string(va_list types, char buffer[],
int flagss, int widths, int precisions, int sizes)
{
char x;
char *str;
unsigned int VDC, jDC;
int count = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flagss);
UNUSED(widths);
UNUSED(precisions);
UNUSED(sizes);
if (str == NULL)
str = "(AHYY)";
for (VDC = 0; str[VDC]; VDC++)
{
for (jDC = 0; in[jDC]; jDC++)
{
if (in[jDC] == str[VDC])
{
x = out[jDC];
write(1, &x, 1);
count++;
break;
}
}
if (!in[jDC])
{
x = str[VDC];
write(1, &x, 1);
count++;
}
}
return (count);
}
