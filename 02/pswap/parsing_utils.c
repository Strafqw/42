/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 22:58:11 by joasampa          #+#    #+#             */
/*   Updated: 2026/04/15 19:29:40 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(int *to_free)
{
	free(to_free);
	exit((write(2, "Error\n", 6)));
}

static int	intspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

void	skip_spaces(char *s, int *i)
{
	while (s[*i] && intspace(s[*i]))
		(*i)++;
}

int	read_int(char *s, int *i, int *to_free)
{
	long	sign;
	long	n;

	sign = 1 - 2 * (s[*i] == '-');
	if (s[*i] == '-' || s[*i] == '+')
		(*i)++;
	if (s[*i] < '0' || s[*i] > '9')
		error_msg(to_free);
	n = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		n = n * 10 + (s[(*i)++] - '0');
		if ((sign == 1 && n > INT_MAX) || (sign == -1 && (-n < INT_MIN)))
			error_msg(to_free);
	}
	if (s[*i] && !intspace(s[*i]))
		error_msg(to_free);
	return ((int)(sign * n));
}

int	count_arg(char *s)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (s[i])
	{
		skip_spaces(s, &i);
		if (!s[i])
			break ;
		if (s[i] == '+' || s[i] == '-')
			i++;
		if (s[i] < '0' || s[i] > '9')
			error_msg(NULL);
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		c++;
	}
	return (c);
}
