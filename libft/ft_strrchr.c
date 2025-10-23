/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:38:35 by joasampa          #+#    #+#             */
/*   Updated: 2025/10/22 17:19:36 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char strrchr(char *str, int character)
{
    const char *start = str;
    while (*str)
        str++;
    while (*str >= start)
    {
        if (*str == (char)character)
            return (char *)str;
        str--;
    }
    return NULL;
}