/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:38:35 by joasampa          #+#    #+#             */
/*   Updated: 2025/10/25 17:59:50 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	size_t i;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	while (i--)
	{
		if (*(str + i) == character)
			return ((char *)(str + i));
	}
	return (NULL);
}
