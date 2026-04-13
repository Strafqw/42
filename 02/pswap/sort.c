/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:17:12 by joasampa          #+#    #+#             */
/*   Updated: 2026/04/10 14:51:54 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted_stack(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->data[i] > a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	sort_two(t_stack *a)
{
	if (a->data[0] > a->data[1])
		sa(a);
}

static void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->data[0];
	y = a->data[1];
	z = a->data[2];
	if (x < y && y < z)
		return ;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size <= 1 || is_sorted_stack(a))
		return ;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_small(a, b);
	else
		radix_sort(a, b);
}
