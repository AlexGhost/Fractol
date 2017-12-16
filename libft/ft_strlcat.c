/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:29:40 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/13 14:56:43 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	j;
	int				len_dest;
	int				taille2;

	i = 0;
	len_dest = ft_strlen((char*)dest);
	while (dest[i] && i < size)
		i++;
	taille2 = i;
	i = 0;
	j = len_dest;
	while (src[i] != '\0' && j < size - 1 && size > 0)
	{
		dest[len_dest + i] = src[i];
		j++;
		i++;
	}
	if (j < size)
		dest[len_dest + i] = '\0';
	return (ft_strlen((char*)src) + taille2);
}
