/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 19:28:45 by joasampa          #+#    #+#             */
/*   Updated: 2026/03/02 23:12:31 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	if (a->size == 0)
		return ;
	i = b->size;
	while (i > 0)
	{
		b->data[i] = b->data[i - 1];
		i--;
	}
	b->data[0] = a->data[0];
	b->size++;
	i = 0;
	while (i < a->size - 1)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->size--;
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	if (b->size == 0)
		return ;
	i = a->size;
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = b->data[0];
	a->size++;
	i = 0;
	while (i < b->size - 1)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	b->size--;
	write(1, "pa\n", 3);
}
