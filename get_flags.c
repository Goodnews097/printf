#include "main.h"
/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.  get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter. get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter. get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter. get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *JD)
{
/* - + 0 # ' ' */
/* 1 2 4 8  16 */
int jf, curr_JD;
int flags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
for (curr_JD = *JD + 1; format[curr_JD] != '\0'; curr_JD++)
{
for (jf = 0; FLAGS_CH[jf] != '\0'; jf++)
if (format[curr_JD] == FLAGS_CH[jf])
{
flags |= FLAGS_ARR[jf];
break;
}
if (FLAGS_CH[jf] == 0)
break;
}
*JD = curr_JD - 1;
return (flags);
}
