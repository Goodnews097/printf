#include <stdio.h>
#include "main.h"
#include <limits.h>
/**
 * main - Entry point main - Entry point main - Entry point main - Entry point
 *
 * Return: main - Entry point main - Entry point Always 0
 */
int main(void)
{
    len = _printf("Let's try to printf a simple sentence.\n");
    int len;
    int len2;
    unsigned int ui;
    void *addr;
    _printf("Length:[%d, %i]\n", len, len);
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Unsigned:[%u]\n", ui);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
_printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");

    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    printf("Character:[%c]\n", 'H');
printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    len2 = printf("Percent:[%%]\n");
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    printf("Unknown:[%r]\n");
    return (0);
}


