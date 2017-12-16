/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:46:26 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/12 19:10:24 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	int				j;
	int				taille;

	taille = 0;
	while (needle[taille] != '\0')
	{
		taille += 1;
	}
	if (taille == 0)
		return ((char*)haystack);
	i = 0;
	j = 0;
	while (haystack[i] != '\0' && i < len)
	{
		while (needle[j] == haystack[i + j] && (i + j) < len)
		{
			if (j == taille - 1)
				return ((char*)haystack + i);
			j += 1;
		}
		j = 0;
		i += 1;
	}
	return (NULL);
}
