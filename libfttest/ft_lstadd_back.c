/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joasampa <joasampa@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:05:08 by joasampa          #+#    #+#             */
/*   Updated: 2025/11/02 18:49:27 by joasampa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *temp;

    if (!lst || !new)
        return;
    if (!*lst) // empty list
    {
        *lst = new;
        return;
    }
    temp = *lst;
    while (temp->next) // walk to the end
        temp = temp->next;
    temp->next = new; // attach new node
}
