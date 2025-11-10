/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:56:53 by joasampa          #+#    #+#             */
/*   Updated: 2025/11/06 20:03:18 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*int main(void)
{
	t_list *n1 = ft_lstnew("one");
	t_list *n2 = ft_lstnew("two");
	t_list *n3 = ft_lstnew("three");

	n1->next = n2;
	n2->next = n3;
	t_list *last = ft_lstlast(n1);
	printf("list content %s\n", (char *)last->content);
	return 0;
}*/