/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:16:53 by joasampa          #+#    #+#             */
/*   Updated: 2025/10/22 17:16:58 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t n)
{
    unsigned char       *d;
    const unsigned char *s;

    if (!dst && !src)
        return NULL;

    d = (unsigned char *)dst;
    s = (const unsigned char *)src;

    if (d == s || n == 0)
        return dst;

    if (d < s) {

        while (n--)
            *d++ = *s++;
    } else {
        d += n;
        s += n;
        while (n--)
            *--d = *--s;
    }
    return dst;
}
