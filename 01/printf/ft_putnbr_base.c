/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:59:33 by joasampa          #+#    #+#             */
/*   Updated: 2025/11/20 21:13:31 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, char *base)
{
	int				count;
	unsigned long	base_len;

	count = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n >= base_len)
		count += ft_putnbr_base(n / base_len, base);
	count += ft_putchar(base[n % base_len]);
	return (count);
}
