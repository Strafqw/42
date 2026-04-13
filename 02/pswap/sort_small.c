/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:00:00 by joasampa          #+#    #+#             */
/*   Updated: 2026/04/10 15:00:00 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	index_of_min(t_stack *a)
{
	int	i;
	int	idx;

	idx = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->data[i] < a->data[idx])
			idx = i;
		i++;
	}
	return (idx);
}

static void	bring_min_to_top(t_stack *a)
{
	int	idx;

	idx = index_of_min(a);
	if (idx <= a->size / 2)
	{
		while (idx-- > 0)
			ra(a);
	}
	else
	{
		idx = a->size - idx;
		while (idx-- > 0)
			rra(a);
	}
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	pushed;

	pushed = 0;
	while (a->size > 3)
	{
		bring_min_to_top(a);
		pb(a, b);
		pushed++;
	}
	sort(a, b);
	while (pushed-- > 0)
		pa(a, b);
}
