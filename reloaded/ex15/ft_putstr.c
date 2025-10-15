#include <unistd.h>

void ft_putchar(char c);

void ft_putstr(char *str)
{
    int i;
    while (str[i])
    {
        ft_putstr(str[i]);
        i++;
    }  
}