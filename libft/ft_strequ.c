/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:03:35 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/13 14:58:03 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(const char *s1, const char *s2)
{
	int i;
	int taille1;
	int taille2;

	if (s1 && s2)
	{
		i = 0;
		taille1 = 0;
		taille2 = 0;
		while (s1[taille1])
			taille1++;
		while (s2[taille2])
			taille2++;
		if (taille1 != taille2)
			return (0);
		while (s1[i] && s2[i])
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
	}
	return (1);
}
