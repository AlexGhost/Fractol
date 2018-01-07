/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:33:55 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/07 16:42:09 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void			color_pix(t_mlx *smlx, int i, float pix[2])
{
	if (i == NB_ITERATION)
		smlx->imgstr[(int)pix[0] + ((int)pix[1] * WIN_WIDTH)] = 0x00000000;
	else
		smlx->imgstr[(int)pix[0] + ((int)pix[1] * WIN_WIDTH)] = \
			0x00000000 - (i * 0x00FF0000) * 10;
}

/*
**		pix:	each pixel on screen
**		z:		pixel that determine the fractal
**		tmp:	tmp of x y and z
*/

static void			*draw_mandelbrot(t_mlx *smlx)
{
	t_mandelbrot		m;

	m.actual_pix = -1;
	while (++m.actual_pix < (WIN_WIDTH * WIN_HEIGHT))
	{
		m.pix[0] = m.actual_pix % WIN_WIDTH;
		m.pix[1] = m.actual_pix / WIN_WIDTH;
		m.z[0] = (m.pix[0] + smlx->offset_x * smlx->zoom / 400 \
				- (WIN_WIDTH / 2.0)) / smlx->zoom;
		m.z[1] = (m.pix[1] + smlx->offset_y * smlx->zoom / 400 \
				- (WIN_HEIGHT / 2.0)) / smlx->zoom;
		m.tmp[0] = m.z[0];
		m.tmp[1] = m.z[1];
		m.iter = -1;
		while (++m.iter < NB_ITERATION && m.z[0] * m.z[0] + m.z[1] * m.z[1] < 4)
		{
			m.tmp[2] = m.z[0];
			m.z[0] = m.z[0] * m.z[0] - m.z[1] * m.z[1] + m.tmp[0];
			m.z[1] = 2 * m.tmp[2] * m.z[1] + m.tmp[1];
		}
		color_pix(smlx, m.iter, m.pix);
	}
	return (NULL);
}

static int			mouseevent(int button, int x, int y, t_mlx *smlx)
{
	if (button == MOUSE_WHEEL_UP)
		smlx->zoom /= 1.1;
	else if (button == MOUSE_WHEEL_DOWN)
		smlx->zoom *= 1.1;
	if (button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN)
	{
		fr_clear_window(smlx, 0x00000000);
		draw_mandelbrot(smlx);
		mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
	}
	return (0);
}

static int			keyevent(int keycode, t_mlx *smlx)
{
	if (keycode == BUTTON_ARROW_UP || keycode == BUTTON_W)
		smlx->offset_y -= 10 * 400 / smlx->zoom;
	else if (keycode == BUTTON_ARROW_DOWN || keycode == BUTTON_S)
		smlx->offset_y += 10 * 400 / smlx->zoom;
	else if (keycode == BUTTON_ARROW_LEFT || keycode == BUTTON_A)
		smlx->offset_x -= 10 * 400 / smlx->zoom;
	else if (keycode == BUTTON_ARROW_RIGHT || keycode == BUTTON_D)
		smlx->offset_x += 10 * 400 / smlx->zoom;
	else if (keycode == BUTTON_Q)
		smlx->zoom /= 1.1;
	else if (keycode == BUTTON_E)
		smlx->zoom *= 1.1;
	if (keycode == BUTTON_ARROW_UP || keycode == BUTTON_W \
		|| keycode == BUTTON_ARROW_DOWN || keycode == BUTTON_S \
		|| keycode == BUTTON_ARROW_LEFT || keycode == BUTTON_A \
		|| keycode == BUTTON_ARROW_RIGHT || keycode == BUTTON_D \
		|| keycode == BUTTON_Q || keycode == BUTTON_E)
	{
		fr_clear_window(smlx, 0x00000000);
		draw_mandelbrot(smlx);
		mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
	}
	return (0);
}

void				fr_mandelbrot(t_mlx *smlx)
{
	smlx->offset_x = -250.0;
	smlx->offset_y = 0.0;
	smlx->zoom = 400.0;
	draw_mandelbrot(smlx);
	mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
	mlx_hook(smlx->win, 2, 0, keyevent, (void*)smlx);
	mlx_mouse_hook(smlx->win, mouseevent, (void*)smlx);
}
