/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:18:24 by joasampa          #+#    #+#             */
/*   Updated: 2025/10/22 17:18:46 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int strlen(char *str);

size_t strlcat(char *dst, const char *src, size_t size)
{
    size_t dst_len = strlen(dst);
    size_t src_len = strlen(src);
    size_t i = 0;

    if (size <= dst_len)    
        return size + src_len; //You gave me a box of size size, but your current stuff (dest) already doesn’t fit. So if you want to fit both dest and src, you’ll need at least size + src_len.
    while (src[i] && (dst_len + i < size - 1)) //size - 1 cos null terminator
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';
    return (dst_len + src_len); // return total len it tried to create
}