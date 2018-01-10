/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:39:42 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/10 14:26:11 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void			color_pix(t_mlx *smlx, float i, int pix)
{
	if (i == NB_ITERATION)
		smlx->imgstr[pix] = 0x000A0A0A;
	else
		smlx->imgstr[pix] = 0x00D0D0D0 * (i / smlx->actual_color);
}

/*
**		pix:	each pixel on screen
**		z:		pixel that determine the fractal
**		tmp:	tmp of x y and z
*/

void				fr_draw_julia(t_mlx *smlx)
{
	t_mandelbrot			m;

	m.actual_pix = -1;
	while (++m.actual_pix < (WIN_WIDTH * WIN_HEIGHT))
	{
		m.pix[0] = m.actual_pix % WIN_WIDTH;
		m.pix[1] = m.actual_pix / WIN_WIDTH;
		m.z[0] = (m.pix[0] + smlx->offset_x * smlx->zoom / 400 \
				- (WIN_WIDTH / 2.0)) / smlx->zoom;
		m.z[1] = (m.pix[1] + smlx->offset_y * smlx->zoom / 400 \
				- (WIN_HEIGHT / 2.0)) / smlx->zoom;
		m.tmp[0] = smlx->varx;
		m.tmp[1] = smlx->vary;
		m.iter = -1;
		while (++m.iter < NB_ITERATION && m.z[0] * m.z[0] + m.z[1] * m.z[1] < 4)
		{
			m.tmp[2] = m.z[0];
			m.z[0] = m.z[0] * m.z[0] - m.z[1] * m.z[1] + m.tmp[0];
			m.z[1] = 2 * m.tmp[2] * m.z[1] + m.tmp[1];
		}
		color_pix(smlx, m.iter, m.actual_pix);
	}
}

static int			mouseevent(int button, int x, int y, t_mlx *smlx)
{
	x = 0;
	y = 0;
	if (button == MOUSE_WHEEL_UP)
		smlx->zoom /= 1.1;
	else if (button == MOUSE_WHEEL_DOWN)
		smlx->zoom *= 1.1;
	if (button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN \
			|| button == MOUSE_LEFT || button == MOUSE_RIGHT)
	{
		fr_clear_window(smlx, 0x00000000);
		fr_draw_julia(smlx);
		mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
	}
	return (0);
}

static int			trackevent(int x, int y, t_mlx *smlx)
{
	if (smlx->block_view == 0)
	{
		smlx->varx = (x - 1000) * 0.001;
		smlx->vary = y * 0.0001;
		fr_clear_window(smlx, 0x00000000);
		fr_draw_julia(smlx);
		mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
	}
	return (0);
}

void				fr_julia(t_mlx *smlx)
{
	smlx->offset_x = 0.0;
	smlx->offset_y = 0.0;
	smlx->zoom = 400.0;
	smlx->varx = 0.285;
	smlx->vary = 0.01;
	smlx->block_view = 1;
	smlx->actual_color = 16;
	fr_draw_julia(smlx);
	mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
	mlx_hook(smlx->win, 2, 0, fr_keyevent_julia, (void*)smlx);
	mlx_mouse_hook(smlx->win, mouseevent, (void*)smlx);
	mlx_hook(smlx->win, 6, 6, trackevent, (void*)smlx);
}
