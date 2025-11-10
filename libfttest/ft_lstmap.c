/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:10:58 by joasampa          #+#    #+#             */
/*   Updated: 2025/11/10 13:50:44 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = ft_lstnew(f(lst->content));
		if (!new_content)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_content);
		lst = lst->next;
	}
	return (new_list);
}

/*
void	*add_exclamation(void *content)
{
	char	*str = (char *)content;
	int		len = 0;
	char	*new;
	int		i = 0;

	while (str[len])
		len++;
	new = malloc(len + 2);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '!';
	new[i + 1] = '\0';
	return (new);
}

void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst = ft_lstnew(ft_strdup("Hello"));
	t_list	*node2 = ft_lstnew(ft_strdup("World"));
	t_list	*result;
	t_list	*tmp;

	ft_lstadd_back(&lst, node2);
	result = ft_lstmap(lst, add_exclamation, del);

	tmp = result;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	ft_lstclear(&lst, del);
	ft_lstclear(&result, del);
	return (0);
}
*/