/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrazao <lfrazao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:55:09 by lfrazao           #+#    #+#             */
/*   Updated: 2025/10/15 15:06:07 by lfrazao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char *))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!tab || !f)
		return (0);
	while (tab[i])
	{
		if (f(tab[i]) == 1)
			count += 1;
		i++;
	}
	return (count);
}
