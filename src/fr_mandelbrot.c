/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:33:55 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/05 15:34:41 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void			pixfractal(t_mlx *smlx, int i, int pix[2])
{
	if (i == NB_ITERATION)
		smlx->imgstr[pix[0] + (pix[1] * WIN_WIDTH)] = 0x00000000;
	else
		smlx->imgstr[pix[0] + (pix[1] * WIN_WIDTH)] = \
			(0x00FF0000 * i) / NB_ITERATION;
}

/*
**		pix:	each pixel on screen
**		z:		pixel that determine the fractal
**		c:		tmp of x y and z
*/

static void			draw_mandelbrot(t_mlx *smlx)
{
	int		pix[2];
	int		i;
	float	z[2];
	float	tmp[3];

	pix[1] = -1;
	while (++pix[1] < WIN_HEIGHT && (pix[0] = -1))
		while (++pix[0] < WIN_WIDTH)
		{
			i = -1;
			z[0] = (pix[0] + smlx->offset_x * smlx->zoom / 400 \
					- (WIN_WIDTH / 2.0)) / smlx->zoom;
			z[1] = (pix[1] + smlx->offset_y * smlx->zoom / 400 \
					- (WIN_HEIGHT / 2.0)) / smlx->zoom;
			tmp[0] = z[0];
			tmp[1] = z[1];
			while (++i < NB_ITERATION && z[0] * z[0] + z[1] * z[1] < 4)
			{
				tmp[2] = z[0];
				z[0] = pow(z[0], 2) - pow(z[1], 2) + tmp[0];
				z[1] = 2 * tmp[2] * z[1] + tmp[1];
			}
			pixfractal(smlx, i, pix);
		}
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
	fr_clear_window(smlx, 0x00000000);
	draw_mandelbrot(smlx);
	mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
	mlx_hook(smlx->win, 2, 0, keyevent, (void*)smlx);
}
