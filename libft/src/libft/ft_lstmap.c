/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:19:08 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/02 11:19:05 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*last_node;

	new_list = 0;
	last_node = 0;
	while (lst && f && del)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		if (!last_node)
		{
			new_list = new_node;
			last_node = new_node;
		}
		last_node->next = new_node;
		last_node = new_node;
		lst = lst->next;
	}
	return (new_list);
}
