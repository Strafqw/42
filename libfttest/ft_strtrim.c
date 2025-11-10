/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:39:56 by joasampa          #+#    #+#             */
/*   Updated: 2025/11/10 14:21:11 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[j - 1]))
		j--;
	return (ft_substr(s1, i, j - i));
}
/*
int main(void)
{
	char const *s = "helloh";
	char const *se = "h";
	printf("%s\n", ft_strtrim(s, se));
	return 0;
}
*/