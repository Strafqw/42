/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:23:36 by joasampa          #+#    #+#             */
/*   Updated: 2025/11/10 23:54:12 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = ft_strlen(s);
	dup = ft_calloc(i + 1, sizeof(char));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, i);
	return (dup);
}
