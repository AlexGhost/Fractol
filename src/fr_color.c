/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:17:53 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/08 16:24:31 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			fr_change_color(int *color)
{
	int i;
	int libcol[4];

	i = 0;
	libcol[0] = 16;
	libcol[1] = 23;
	libcol[2] = 30;
	libcol[3] = 32;
	while (i < 4)
	{
		if (*color == libcol[i])
		{
			if (i == 3)
				*color = libcol[0];
			else
				*color = libcol[i + 1];
			break ;
		}
		i++;
	}
}
