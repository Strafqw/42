/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrazao <lfrazao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:08:49 by lfrazao           #+#    #+#             */
/*   Updated: 2025/10/14 18:15:25 by lfrazao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	arr = malloc(4 * (max - min));
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}

/*
int	main(void)
{
	printf("%d", *ft_range(10, 20));
}
*/