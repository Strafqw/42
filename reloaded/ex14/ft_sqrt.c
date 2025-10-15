#include <stdio.h>

int	ft_sqrt(int nb)
{
	long i;

    i = 1;

    if (nb <= 0)
    {
        return 0;
    }
    while (i * i <= nb)
    {
        if (i * i == nb)
        return i;
        i++;
    } 
    return 0;   
}

int main(void)
{
    int result = ft_sqrt(81);
    printf("%d\n", result);
    return 0;
}
