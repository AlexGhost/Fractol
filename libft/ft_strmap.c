/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:40:22 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/13 14:57:08 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		taille;
	int		i;
	char	*str;

	taille = 0;
	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[taille])
		taille++;
	str = malloc(sizeof(char) * (taille + 1));
	if (!str)
		return (NULL);
	while (i < taille)
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
