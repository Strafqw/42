/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:18:24 by joasampa          #+#    #+#             */
/*   Updated: 2025/10/25 17:50:22 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t data[3];

	data[0] = ft_strlen(dst);
	data[1] = ft_strlen(src);
	data[2] = 0;
	if (size <= data[0])
		return (size + data[1]);
	while (src[data[2]] && (data[0] + data[2] < size - 1))
	{
		dst[data[0] + data[2]] = src[data[2]];
		data[2]++;
	}
	dst[data[0] + data[2]] = '\0';
	return (data[0] + data[1]);
}
