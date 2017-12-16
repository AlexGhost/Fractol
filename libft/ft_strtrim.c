/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:34:42 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/13 14:59:56 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_trim(const char *s, char *str, int i, int k)
{
	int j;
	int go;

	j = 0;
	go = 1;
	while (s[i] && go)
	{
		str[j] = s[i];
		i++;
		j++;
		k = i;
		while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
		{
			k++;
			if (s[k] == '\0')
				go = 0;
		}
	}
	str[j] = '\0';
}

char			*ft_strtrim(const char *s)
{
	char	*str;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1))))
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	k = i;
	ft_trim(s, str, i, k);
	return (str);
}
