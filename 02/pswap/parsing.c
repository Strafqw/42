/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 22:58:11 by joasampa          #+#    #+#             */
/*   Updated: 2026/04/10 17:09:36 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_ints(int ac, char **av)
{
	int	c;
	int	a;

	a = 1;
	c = 0;
	while (a < ac)
	{
		c += count_arg(av[a]);
		a++;
	}
	return (c);
}

static void	check_dups(int *t, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (t[i] == t[j])
				error_msg();
			j++;
		}
		i++;
	}
}

static void	fill_array(int *t, int ac, char **av)
{
	int	a;
	int	i;
	int	k;

	a = 1;
	k = 0;
	while (a < ac)
	{
		i = 0;
		while (av[a][i])
		{
			skip_spaces(av[a], &i);
			if (!av[a][i])
				break ;
			t[k++] = read_int(av[a], &i);
		}
		a++;
	}
}

int	*parse(int ac, char **av, int *n)
{
	int	*t;

	*n = count_ints(ac, av);
	if (*n == 0)
		error_msg();
	t = malloc(sizeof(int) * (*n));
	if (!t)
		exit(1);
	fill_array(t, ac, av);
	check_dups(t, *n);
	return (t);
}
