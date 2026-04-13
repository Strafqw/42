/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 23:17:49 by joasampa          #+#    #+#             */
/*   Updated: 2026/03/02 23:17:59 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s, int *numbers, int n)
{
	int	i;

	s->data = (int *)malloc(sizeof(int) * n);
	if (!s->data)
		exit(1);
	i = 0;
	while (i < n)
	{
		s->data[i] = numbers[i];
		i++;
	}
	s->size = n;
}
