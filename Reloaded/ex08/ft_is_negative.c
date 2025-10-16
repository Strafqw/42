/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrazao <lfrazao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:07:42 by lfrazao           #+#    #+#             */
/*   Updated: 2025/10/15 15:21:45 by lfrazao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		ft_putchar('N');
	}
	else if (n >= 0)
	{
		ft_putchar('P');
	}
}

/*
int	main(void)
{
	ft_is_negative(1);
	ft_is_negative(-1);
	ft_is_negative(0);
	return (0);
}
*/