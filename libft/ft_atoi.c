/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:25:12 by joasampa          #+#    #+#             */
/*   Updated: 2025/10/18 18:28:48 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int atoi(const char *str)
{
    int i;
    int sign;
    int resultado;

    i = 0;
    resultado = 0;
    sign = 1;
    while (*(str + i) == ' ' || (*(str + i) >= 9 && *(str + i) <= 13))
        i++;
    if (*(str + i) == '+' || *(str + i) == '-')
        sign = (*(str + i) == '+') - (*(str + i++) == '-');
    while (*(str + i) >= '0' && *(str + i) <= '9')
        resultado = resultado * 10 + (*(str + i++) - '0');
    return (resultado * sign);
}
