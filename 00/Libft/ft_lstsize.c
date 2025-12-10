/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:29:54 by joasampa          #+#    #+#             */
/*   Updated: 2025/11/07 14:30:12 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*int main(void)
{
	t_list *n1 = ft_lstnew("one");
	t_list *n2 = ft_lstnew("two");
	t_list *n3 = ft_lstnew("three");

	n1->next = n2;
	n2->next = n3;
	printf("list size %d\n", ft_lstsize(n1));
	return 0;
}*/