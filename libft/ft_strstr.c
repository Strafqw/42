/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:19:32 by joasampa          #+#    #+#             */
/*   Updated: 2025/10/19 23:06:08 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *strstr(const char *haystack, const char *needle)
{
    const char *h; 
    const char *n;

    if (*needle == '\0') //se o 1º char for nulo 
        return (char *)haystack; //da cast e retorna a str
    while (*haystack)
    {
        h = haystack;
        n = needle;
        while (*h && *n && (*h == *n))
        {
            h++;
            n++;
        }
        if (*n == '\0')
            return (char *)haystack;
        haystack++;
    }
    return NULL;
}
