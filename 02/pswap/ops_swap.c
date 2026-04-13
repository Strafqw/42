/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 19:28:55 by joasampa          #+#    #+#             */
/*   Updated: 2026/02/27 19:28:58 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->data[0];
	a->data[0] = a->data[1];
	a->data[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->data[0];
	b->data[0] = b->data[1];
	b->data[1] = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	t;

	if (a->size >= 2)
	{
		t = a->data[0];
		a->data[0] = a->data[1];
		a->data[1] = t;
	}
	if (b->size >= 2)
	{
		t = b->data[0];
		b->data[0] = b->data[1];
		b->data[1] = t;
	}
	write(1, "ss\n", 3);
}
