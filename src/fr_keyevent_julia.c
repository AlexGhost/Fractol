/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_keyevent_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 17:26:56 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/07 17:40:06 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		draw_julia(t_mlx *smlx)
{
	fr_clear_window(smlx, 0x00000000);
	fr_draw_julia(smlx);
	mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
}

int				fr_keyevent_julia(int keycode, t_mlx *smlx)
{
	if (keycode == BUTTON_W)
		smlx->offset_y -= 10 * 400 / smlx->zoom;
	else if (keycode == BUTTON_S)
		smlx->offset_y += 10 * 400 / smlx->zoom;
	else if (keycode == BUTTON_A)
		smlx->offset_x -= 10 * 400 / smlx->zoom;
	else if (keycode == BUTTON_D)
		smlx->offset_x += 10 * 400 / smlx->zoom;
	else if (keycode == BUTTON_Q)
		smlx->zoom /= 1.1;
	else if (keycode == BUTTON_E)
		smlx->zoom *= 1.1;
	else if (keycode == BUTTON_B)
	{
		if (smlx->block_view == 0)
			smlx->block_view = 1;
		else
			smlx->block_view = 0;
	}
	if (keycode == BUTTON_W || keycode == BUTTON_S || keycode == BUTTON_A \
			|| keycode == BUTTON_D || keycode == BUTTON_Q \
			|| keycode == BUTTON_E)
		draw_julia(smlx);
	return (0);
}
