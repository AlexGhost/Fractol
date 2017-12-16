/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:36:34 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/16 16:37:19 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		Ajoute l'element new_elem a la fin de la liste alst.
*/

#include "libft.h"

void			ft_lsttail(t_list **alst, t_list *new_elem)
{
	t_list		*curlist;

	curlist = *alst;
	if (curlist)
	{
		while (curlist->next)
			curlist = curlist->next;
		curlist->next = new_elem;
	}
	else
		*alst = new_elem;
}
