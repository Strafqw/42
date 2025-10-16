/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrazao <lfrazao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:30:00 by lfrazao           #+#    #+#             */
/*   Updated: 2025/10/13 15:37:23 by lfrazao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((s1[i] > s2[i]) || (s1[i] < s2[i]))
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

/*
int	main(void)
{
	printf("%d", ft_strcmp("", "a"));
	printf("\n");
	printf("%d", ft_strcmp("a", ""));
	printf("\n");
	printf("%d", ft_strcmp("a", "a"));
}
*/