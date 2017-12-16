/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:25:29 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/12 19:16:24 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int taille;

	taille = 0;
	while (needle[taille] != '\0')
	{
		taille += 1;
	}
	if (taille == 0)
		return ((char*)haystack);
	i = 0;
	j = 0;
	while (haystack[i] != '\0')
	{
		while (needle[j] == haystack[i + j])
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
