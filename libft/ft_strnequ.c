/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:00:32 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/13 14:58:39 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;
	unsigned long	taille1;
	unsigned long	taille2;

	if (s1 && s2)
	{
		i = 0;
		taille1 = 0;
		taille2 = 0;
		while (s1[taille1] != '\0' && taille1 < n)
			taille1++;
		while (s2[taille2] != '\0' && taille2 < n)
			taille2++;
		if (taille1 != taille2)
			return (0);
		while ((s1[i] && s2[i]) && i < n)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
	}
	return (1);
}
