#include "main.h"
/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *VD)
{
int curr_VD = *VD + 1;
int size = 0;
if (format[curr_VD] == 'l')
size = S_LONG;
else if (format[curr_VD] == 'h')
size = S_SHORT;
if (size == 0)
*VD = curr_VD - 1;
else
*VD = curr_VD;
return (size);
}
