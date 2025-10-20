/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:37:38 by joasampa          #+#    #+#             */
/*   Updated: 2025/10/19 22:37:40 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

strcat(char *dst, const char *src)
{
    int i;
    int j;

    i = 0;
    while (dst[i])
    {
        i++;
    }
    while (src[j])
    {
        dst[i] = src[j];
        j++;
        i++;
    }
    dst[i] = '\0';
    return dst;
}