/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:37:43 by joasampa          #+#    #+#             */
/*   Updated: 2025/10/19 22:37:45 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *strchr(const char *str, int character)
{
    while (*str)
    {
        if (*str == (char)character)
            return (char *)str;
        str++;
    }
    if (*str == (char)character)
        return (char *)str;
    return 0;
}
