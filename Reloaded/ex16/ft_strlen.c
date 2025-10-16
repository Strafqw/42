/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrazao <lfrazao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:27:19 by lfrazao           #+#    #+#             */
/*   Updated: 2025/10/13 15:29:26 by lfrazao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*
int	main(void)
{
	printf("%d", ft_strlen(""));
	printf("\n");
	printf("%d", ft_strlen("Hello"));
	printf("\n");
	printf("%d", ft_strlen("lol"));
}
*/