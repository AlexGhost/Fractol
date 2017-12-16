/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:29:21 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/11 16:46:58 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*curlist;

	curlist = *alst;
	while (curlist->next != NULL)
	{
		del(curlist->content, curlist->content_size);
		free(curlist);
		curlist = curlist->next;
	}
	del(curlist->content, curlist->content_size);
	free(curlist);
	*alst = NULL;
}
