/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:07:07 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/12 21:09:34 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstrev(t_list **lst)
{
	t_list *tmp_begin;
	t_list *tmp_beforelast;
	t_list *tmp_last;

	tmp_begin = *lst;
	if (tmp_begin != 0)
	{
		tmp_beforelast = *lst;
		tmp_last = ft_lstlast(*lst);
		if (tmp_beforelast->next != 0)
		{
			while (tmp_beforelast->next->next != 0)
			{
				tmp_beforelast = tmp_beforelast->next;
			}
			tmp_beforelast->next = 0;
			ft_lstrev(&tmp_begin);
			tmp_last->next = tmp_begin;
			*lst = tmp_last;
		}
	}
}
