/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:38:20 by joasampa          #+#    #+#             */
/*   Updated: 2025/10/19 22:38:22 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *strncat(char *dest, const char *src, size_t n)
{
    size_t i;
    size_t j;
    
    j = 0;
    i = 0;
    while (dest[i])
    {
        i++;
    }
    while (src[j] && j < n)
    {
        dest[i] = src[j];
        j++;
        i++;
    }
    dest[i] = '\0';
    return dest;
}