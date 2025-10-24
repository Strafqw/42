/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:38:06 by joasampa          #+#    #+#             */
/*   Updated: 2025/10/22 17:25:03 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	if (s1 == NULL)
	{
		return (NULL);
	}
	dup = malloc(ft_strlen(s1) + 1);
	if (dup == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
