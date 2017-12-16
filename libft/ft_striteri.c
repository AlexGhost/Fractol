/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:18:36 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/11 22:02:58 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	*c;
	int		i;
	int		taille;

	if (s && f)
	{
		c = s;
		i = 0;
		taille = 0;
		while (c[0])
		{
			c++;
			taille++;
		}
		while (i < taille)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
