/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:02:59 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/12 17:39:05 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*newlist;
	t_list		*curlist;
	t_list		**ptr;

	if (lst)
	{
		curlist = lst;
		newlist = ft_lstnew(f(curlist)->content, f(curlist)->content_size);
		if (!newlist)
			return (NULL);
		ptr = &newlist;
		while (curlist->next != NULL)
		{
			curlist = curlist->next;
			ft_lsttail(ptr, ft_lstnew(f(curlist)->content,
						f(curlist)->content_size));
		}
	}
	else
		newlist = NULL;
	return (newlist);
}
