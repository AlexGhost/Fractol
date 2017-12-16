/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:21:12 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/27 12:20:51 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char*)s;
	while (ptr[i] != '\0')
		i++;
	i--;
	if (c == '\0')
		return (ptr + i + 1);
	while (i >= 0)
	{
		if (ptr[i] == c)
			return (ptr + i);
		i--;
	}
	return (NULL);
}
