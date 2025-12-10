/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:28:33 by joasampa          #+#    #+#             */
/*   Updated: 2025/11/21 16:21:55 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pp(void *ptr)
{
	unsigned long	addr;
	int				len;

	if (!ptr)
		return (ft_putstr("(nil)"));
	addr = (unsigned long)ptr;
	len = ft_putstr("0x");
	len += ft_putnbr_base(addr, "0123456789abcdef");
	return (len);
}
