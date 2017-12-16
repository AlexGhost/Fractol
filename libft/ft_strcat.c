/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:13:21 by acourtin          #+#    #+#             */
/*   Updated: 2017/11/12 19:11:51 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int taille;

	i = 0;
	taille = 0;
	while (dest[taille] != '\0')
	{
		taille += 1;
	}
	while (src[i] != '\0')
	{
		dest[taille + i] = src[i];
		i += 1;
	}
	dest[taille + i] = '\0';
	return (dest);
}
