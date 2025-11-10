/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:23:55 by joasampa          #+#    #+#             */
/*   Updated: 2025/11/10 00:58:23 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	intlen(int nb)
{
	long	n;
	int		len;

	n = nb;
	len = (n <= 0);
	if (n < 0)
		n = -n;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*s;

	nb = n;
	len = intlen(nb);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len--] = '\0';
	if (nb < 0)
		nb = -nb;
	if (nb == 0)
		s[0] = '0';
	while (nb)
	{
		s[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
/*
int main(void)
{
	printf("%s\n", ft_itoa(-12334));
	return 0;
}*/