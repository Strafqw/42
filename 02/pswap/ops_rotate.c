/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:16:35 by joasampa          #+#    #+#             */
/*   Updated: 2026/03/28 19:16:38 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	int	i;
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->data[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->data[a->size - 1] = temp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	int	i;
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->data[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	b->data[b->size - 1] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	int	i;
	int	temp;

	if (a->size < 2 || b->size < 2)
		return ;
	temp = a->data[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->data[a->size - 1] = temp;
	temp = b->data[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	b->data[b->size - 1] = temp;
	write(1, "rr\n", 3);
}
