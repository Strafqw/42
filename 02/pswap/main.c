/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:16:48 by joasampa          #+#    #+#             */
/*   Updated: 2026/03/28 19:16:50 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		*numbers;
	int		n;
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	numbers = parse(ac, av, &n);
	if (is_sorted(numbers, n))
	{
		free(numbers);
		return (0);
	}
	init_stack(&a, numbers, n);
	a.size = n;
	b.data = (int *)malloc(sizeof(int) * n);
	if (!b.data)
		exit(1);
	b.size = 0;
	sort(&a, &b);
	free(a.data);
	free(b.data);
	free(numbers);
	return (0);
}
