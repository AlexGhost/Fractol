/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:55:58 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/14 15:02:47 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*curlist;

	count = 0;
	curlist = lst;
	if (curlist == NULL)
		return (0);
	while (curlist->next != 0)
	{
		curlist = curlist->next;
		count += 1;
	}
	count += 1;
	return (count);
}
