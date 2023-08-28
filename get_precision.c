#include "main.h"
/**
 * get_precision - Calculates the precision for get_precision - Calculates the precision for printingget_precision - Calculates the precision for printingget_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the argumentsget_precision - Calculates the precision for printingget_precision - Calculates the precision for printingget_precision - Calculates the precision for printing
 * @i: List of arguments to be printed.get_precision - Calculates the precision for printingget_precision - Calculates the precision for printing
 * @list: list of arguments.get_precision - Calculates the precision for printingget_precision - Calculates the precision for printing
 *get_precision - Calculates the precision for printingget_precision - Calculates the precision for printingget_precision - Calculates the precision for printing
 * Return: Precision.get_precision - Calculates the precision for printingget_precision - Calculates the precision for printing
 */
int get_precision(const char *format, int *VD, va_list list)
{
int curr_VD = *VD + 1;
int precision = -1;
if (format[curr_VD] != '.')
return (precision);
precision = 0;
for (curr_VD += 1; format[curr_VD] != '\0'; curr_VD++)
{
if (is_digit(format[curr_VD]))
{
precision *= 10;
precision += format[curr_VD] - '0';
}
else if (format[curr_VD] == '*')
{
curr_VD++;
precision = va_arg(list, int);
break;
}
else
break;
}
*VD = curr_VD - 1;
return (precision);
}
