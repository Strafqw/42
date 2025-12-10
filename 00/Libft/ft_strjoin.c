/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:34:51 by joasampa          #+#    #+#             */
/*   Updated: 2025/10/24 18:08:39 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	total;

	if (!s1 || !s2)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2);
	join = ft_calloc(total + 1, sizeof(char));
	if (!join)
		return (NULL);
	ft_memcpy(join, s1, ft_strlen(s1));
	ft_memcpy(join + ft_strlen(s1), s2, ft_strlen(s2));
	return (join);
}

/*int main(void)
{
	char s1[] = "Hello";
	char s2[] = " world";
	char    *p;

	p = ft_strjoin(s1, s2);
	printf("T1: %s\n T2: %s\n Res: %s", s1, s2, p);
	return (0);
}*/
