/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:04:48 by joasampa          #+#    #+#             */
/*   Updated: 2025/10/22 17:16:32 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *memchr(const void *s1, int c, size_t n)
{
    const unsigned char *p1 = (unsigned char*)s1;
    unsigned char uc = (unsigned char)c; // you could cast in loop but u do it here for efficiency

    while (n--)
    {
        if (*p1 == uc)
        {
            return (void *)p1;
        }
        p1++;
    }
    return NULL;
}