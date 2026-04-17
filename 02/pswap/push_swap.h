/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:17:02 by joasampa          #+#    #+#             */
/*   Updated: 2026/03/28 19:17:04 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*data;
	int	size;
}		t_stack;

/* parsing */
void	error_msg(int *to_free);
void	skip_spaces(char *s, int *i);
int		read_int(char *s, int *i, int *to_free);
int		count_arg(char *s);
int		*parse(int ac, char **av, int *n);

/* init */
void	init_stack(t_stack *s, int *numbers, int n);

/* swap */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

/* push */
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

/* rotate */
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

/* reverse rotate */
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* sort */
void	sort(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

#endif
