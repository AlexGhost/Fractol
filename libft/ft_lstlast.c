/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:10:18 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/12 21:10:39 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	t_list *curlist;

	curlist = lst;
	if (curlist != 0)
	{
		while (curlist->next != 0)
			curlist = curlist->next;
		return (curlist);
	}
	else
		return (0);
}
