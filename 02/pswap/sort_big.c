/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:17:06 by joasampa          #+#    #+#             */
/*   Updated: 2026/04/12 15:35:29 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	normalize(t_stack *a)
{
	int	*tmp;
	int	i;
	int	j;

	tmp = (int *)malloc(sizeof(int) * a->size);
	if (!tmp)
		exit(1);
	i = -1;
	while (++i < a->size)
	{
		tmp[i] = 0;
		j = -1;
		while (++j < a->size)
			if (a->data[j] < a->data[i])
				tmp[i]++;
	}
	i = -1;
	while (++i < a->size)
		a->data[i] = tmp[i];
	free(tmp);
}

static int	get_max_bits(int n)
{
	int	bits;

	bits = 0;
	while ((n - 1) >> bits)
		bits++;
	return (bits);
}

static void	radix_bit(t_stack *a, t_stack *b, int bit)
{
	int	i;
	int	size;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if ((a->data[0] >> bit) & 1)
			ra(a);
		else
			pb(a, b);
		i++;
	}
	while (b->size > 0)
		pa(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bit;
	int	max_bits;

	normalize(a);
	max_bits = get_max_bits(a->size);
	bit = 0;
	while (bit < max_bits)
	{
		radix_bit(a, b, bit);
		bit++;
	}
}
