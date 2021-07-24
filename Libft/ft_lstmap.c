/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:31:04 by achobany          #+#    #+#             */
/*   Updated: 2021/02/03 15:28:35 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*start;

	if (!(start = ft_lstnew(f(lst->content))))
		ft_lstdelone(lst, del);
	else
	{
		lst = lst->next;
		tmp = start;
	}
	while (lst)
	{
		if (!(tmp->next = ft_lstnew(f(lst->content))))
			ft_lstdelone(lst, del);
		lst = lst->next;
		tmp = tmp->next;
	}
	return (start);
}
