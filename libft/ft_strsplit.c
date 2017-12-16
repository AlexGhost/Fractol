/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:21:21 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/13 15:02:51 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	int t;
	int i;
	int space;

	i = 0;
	t = 0;
	space = 0;
	if (!s[0])
		return (0);
	if (s[0] != c)
		t += 1;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && space == 1)
		{
			t += 1;
			space = 0;
		}
		else if (s[i] == c)
			space = 1;
		else
			space = 0;
		i += 1;
	}
	return (t);
}

static void	ft_stock_char(const char *str, char **res, char c)
{
	int i;
	int j;
	int z;

	i = 0;
	j = 0;
	z = 0;
	while (str[i])
	{
		if (str[i] == c && j)
		{
			res[z][j] = '\0';
			j = 0;
			z += 1;
		}
		else if (str[i] != c || j)
		{
			res[z][j] = str[i];
			j += 1;
		}
		i += 1;
	}
	if (j != 0)
		res[z][j] = '\0';
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	words = ft_countwords(s, c);
	tab = malloc(sizeof(char*) * (words + 30));
	if (!tab)
		return (NULL);
	while (i < words)
	{
		tab[i] = malloc(sizeof(char) * ft_strlen((char*)s));
		if (!tab[i])
			return (NULL);
		i++;
	}
	i = 0;
	while (i < words)
		i++;
	tab[i] = 0;
	ft_stock_char(s, tab, c);
	return (tab);
}
