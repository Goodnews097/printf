#include "main.h"
/**
 * get_width - Calculates the width for printing get_width - Calculates the width for printing get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.get_width - Calculates the width for printing
 * @i: List of arguments to be printed. get_width - Calculates the width for printing
 * @list: list of arguments. get_width - Calculates the width for printing
 * get_width - Calculates the width for printing
 * Return: width.
 */
int get_width(const char *format, int *VD, va_list list)
{
int curr_VD;
int width = 0;
for (curr_VD = *VD + 1; format[curr_VD] != '\0'; curr_VD++)
{
if (is_digit(format[curr_VD]))
{
width *= 10;
width += format[curr_VD] - '0';
}
else if (format[curr_VD] == '*')
{
curr_VD++;
width = va_arg(list, int);
break;
}
else
break;
}
*VD = curr_VD - 1;
return (width);
}
