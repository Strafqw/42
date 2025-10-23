/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:42:29 by joasampa          #+#    #+#             */
/*   Updated: 2025/10/22 17:42:43 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t  ft_strlcpy(char *dest, const char *src, size_t size)
{
    unsigned int    i;
    unsigned int    len;
    len = ft_strlen(src);
    i = 0;
    if (size > 0)
    {
        while (i < size - 1 && src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
    return (len);
}
