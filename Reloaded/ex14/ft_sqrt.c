/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrazao <lfrazao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:14:48 by lfrazao           #+#    #+#             */
/*   Updated: 2025/10/13 15:21:37 by lfrazao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	x;

	x = 1;
	if (nb <= 0)
		return (0);
	while ((x * x) <= nb)
	{
		if ((x * x) == nb)
			return (x);
		x++;
	}
	return (0);
}

/*
int	main(void)
{
	printf("%d\n", ft_sqrt(-1));
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(16));
	return (0);
}
*/