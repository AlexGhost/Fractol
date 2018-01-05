/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_colormania.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:47:30 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/05 15:37:40 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int			loopmania(t_mlx *smlx)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			smlx->imgstr[x + (y * WIN_WIDTH)] = smlx->actual_color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
	smlx->actual_color += sin(smlx->actual_color += 0x00010105);
	return (0);
}

void				fr_colormania(t_mlx *smlx)
{
	mlx_loop_hook(smlx->mlx, loopmania, (void*)smlx);
}
