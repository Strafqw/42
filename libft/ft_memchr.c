/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:04:48 by joasampa          #+#    #+#             */
/*   Updated: 2025/10/24 18:22:28 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memchr(const void *s1, int c, size_t n)
{
	unsigned char	*p1;
	unsigned char	uc;

	p1 = (unsigned char *)s1;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*p1 == uc)
		{
			return ((void *)p1);
		}
		p1++;
	}
	return (NULL);
}
