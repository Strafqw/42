/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:00:57 by joasampa          #+#    #+#             */
/*   Updated: 2025/11/07 13:01:08 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	i = ft_strlen(s + start);
	if (len > i)
		len = i;
	sub = (char *)ft_calloc(len + 1, sizeof(char));
	ft_memcpy(sub, s + start, len);
	return (sub);
}
/*
int main(void)
{
	char const *str = "Hello";
	unsigned int start = 2;
	size_t len = 3;
	printf("%s\n", ft_substr(str, start, len));
}*/