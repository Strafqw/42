/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:00:57 by joasampa          #+#    #+#             */
/*   Updated: 2025/10/23 17:20:49 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sub;
    
    if (!s)
        return NULL;
    sub = (char *)ft_calloc(len + 1, sizeof(char));
    ft_memcpy(sub, s + start, len); 
    return sub;
} 