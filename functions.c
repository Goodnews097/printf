#include "main.h"
/************************* PRINT CHAR *************************/
/**
 * print_char - Prints a charprint_char - Prints a charprint_char - Prints a charprint_char - Prints a charprint_char - Prints a charprint_char - Prints a char
 * @types: List a of argumentsprint_char - Prints a charprint_char - Prints a charprint_char - Prints a char
 * @buffer: Buffer array to handle printprint_char - Prints a charprint_char - Prints a charprint_char - Prints a charprint_char - Prints a charprint_char - Prints a char
 * @flags:  Calculates active flag  print_char - Prints a charprint_char - Prints a charprint_char - Prints a charprint_char - Prints a char print_char - Prints a charprint_char - Prints a chars
 * @width: Width print_char - Prints a charprint_char - Prints a charprint_char - Prints a charprint_char - Prints a char
 * @precision: Precision specificationprint_char - Prints a charprint_char - Prints a charprint_char - Prints a charprint_char - Prints a char
 * @size: Size specifierprint_char - Prints a charprint_char - Prints a charprint_char - Prints a charprint_char - Prints a char
 * Return: Number of chars printed print_char - Prints a charprint_char - Prints a charprint_char - Prints a charprint_char - Prints a char
 */
int print_char(va_list types, char buffer[],
int flagsss, int widthsss, int precisionsss, int sizesss)
{
char c = va_arg(types, int);
return (handle_write_char(c, buffer, flagsss, widthsss, precisionsss, sizesss));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a stringprint_char - Prints a charprint_char - Prints a charprint_char - Prints a charprint_char - Prints a char
 * @types: List a of argumentsprint_char - Prints a charprint_char - Prints a charprint_char - Prints a charprint_char - Prints a char
 * @buffer: Buffer array to handle printprint_char - Prints a charprint_char - Prints a charprint_char - Prints a charprint_char - Prints a char
 * @flags:  Calculates active flaprint_char - Prints a charprint_char - Prints a charprint_char - Prints a charprint_char - Prints a chargs
 * @width: get print_char - Prints a charprint_char - Prints a charprint_char - Prints a char
 * @precision: Precision print_char - Prints a charprint_char - Prints a charprint_char - Prints a charprint_char - Prints a charprint_char - Prints a char
 * @size: Size specifierprint_char - Prints a charprint_char - Prints a charprint_char - Prints a charprint_char - Prints a char
 * Return: Number of chars printedprint_char - Prints a charprint_char - Prints a charprint_char - Prints a char
 */
int print_string(va_list types, char buffer[],
int flagsss, int widthsss, int precisionsss, int sizesss)
{
int lengths = 0, VD;
char *str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flagsss);
UNUSED(widthsss);
UNUSED(precisionsss);
UNUSED(sizesss);
if (str == NULL)
{
str = "(null)";
if (precisionsss >= 6)
str = "      ";
}
while (str[lengths] != '\0')
lengths++;
if (precisionsss >= 0 && precisionsss < lengths)
lengths = precisionsss;
if (widthsss > lengths)
{
if (flagsss & F_MINUS)
{
write(1, &str[0], lengths);
for (i = widthsss - lengths; VD > 0; VD--)
write(1, " ", 1);
return (widthsss);
}
else
{
for (i = widthsss - lengths; VD > 0; VD--)
write(1, " ", 1);
write(1, &str[0], lengths);
return (widthsss);
}
}
return (write(1, str, lengths));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments print_percent - Prints a percent signprint_percent - Prints a percent signprint_percent - Prints a percent sign
 * @buffer: Buffer array to handle print print_percent - Prints a percent signprint_percent - Prints a percent signprint_percent - Prints a percent sign
 * @flags:  Calculates active flags print_percent - Prints a percent signprint_percent - Prints a percent signprint_percent - Prints a percent sign
 * @width: get width. print_percent - Prints a percent signprint_percent - Prints a percent signprint_percent - Prints a percent sign
 * @precision: Precision specification
 * @size: Size specifier print_percent - Prints a percent signprint_percent - Prints a percent sign
 * Return: Number of chars printed print_percent - Prints a percent signprint_percent - Prints a percent sign
 */
int print_percent(va_list types, char buffer[],
int flagsss, int widthsss, int precisionsss, int sizesss)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flagsss);
UNUSED(widthsss);
UNUSED(precisionsss);
UNUSED(sizesss);
return (write(1, "%%", 1));
}
/************************* PRINT INT *************************/
/**
 * print_int - Print int print_int - Print intprint_int - Print intprint_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to h  print_int - Print intprint_int - Print intprint_int - Print int andle print
 * @flags:  Calculates active flagsprint_int - Print intprint_int - Print intprint_int - Print intprint_int - Print int 
 * @width: get width.print_int - Print intprint_int - Print intprint_int - Print intprint_int - Print int
 * @precision: Precision specificationprint_int - Print intprint_int - Print intprint_int - Print intprint_int - Print int
 * @size: Size specifierprint_int - Print intprint_int - Print intprint_int - Print intprint_int - Print int
 * Return: Number of chars printedprint_int - Print intprint_int - Print intprint_int - Print intprint_int - Print int
 */
int print_int(va_list types, char buffer[],
int flagsss, int widthsss, int precisionsss, int sizesss)
{
int i = BUFF_SIZE - 2;
int is_negative = 0;
long int n = va_arg(types, long int);
unsigned long int num;
n = convert_size_number(n, sizesss);
if (n == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;
if (n < 0)
{
num = (unsigned long int)((-1) * n);
is_negative = 1;
}
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
int flagsss, int widthsss, int precisionsss, int sizesss)
{
unsigned int n, m, i, sum;
unsigned int a[32];
int count;
UNUSED(buffer);
UNUSED(flagsss);
UNUSED(widthsss);
UNUSED(precisionsss);
UNUSED(sizesss);
n = va_arg(types, unsigned int);
m = 2147483648; /* (2 ^ 31) */
a[0] = n / m;
for (i = 1; i < 32; i++)
{
m /= 2;
a[i] = (n / m) % 2;
}
for (i = 0, sum = 0, count = 0; i < 32; i++)
{
sum += a[i];
if (sum || i == 31)
{
char z = '0' + a[i];
write(1, &z, 1);
count++;
}
}
return (count);
}
