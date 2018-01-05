/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:33:55 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/05 18:01:34 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** start color:	003366
** end color:	FFFFFF
*/

static void			pixfractal(t_mlx *smlx, int i, int pix[2])
{
	if (i == NB_ITERATION)
		smlx->imgstr[pix[0] + (pix[1] * WIN_WIDTH)] = 0x00003366;
	else
		smlx->imgstr[pix[0] + (pix[1] * WIN_WIDTH)] = \
			0x00003366 + ((0x00FFFFFF - 0x00003366) * i * 15);
}

/*
**		pix:	each pixel on screen
**		z:		pixel that determine the fractal
**		c:		tmp of x y and z
*/

static void			*draw_mandelbrot(void *p)
{
	t_fractal_thread	*arg;
	t_mandelbrot		m;
	int					i;

	arg = p;
	m.pix[1] = arg->pix_start[1] - 1;
	while (++m.pix[1] < arg->pix_end[1] && (m.pix[0] = arg->pix_start[0] - 1))
		while (++m.pix[0] < arg->pix_end[0] && (i = -1))
		{
			m.z[0] = (m.pix[0] + arg->smlx->offset_x * arg->smlx->zoom / 400 \
					- (WIN_WIDTH / 2.0)) / arg->smlx->zoom;
			m.z[1] = (m.pix[1] + arg->smlx->offset_y * arg->smlx->zoom / 400 \
					- (WIN_HEIGHT / 2.0)) / arg->smlx->zoom;
			m.tmp[0] = m.z[0];
			m.tmp[1] = m.z[1];
			while (++i < NB_ITERATION && m.z[0] * m.z[0] + m.z[1] * m.z[1] < 4)
			{
				m.tmp[2] = m.z[0];
				m.z[0] = m.z[0] * m.z[0] - m.z[1] * m.z[1] + m.tmp[0];
				m.z[1] = 2 * m.tmp[2] * m.z[1] + m.tmp[1];
			}
			pixfractal(arg->smlx, i, m.pix);
		}
	return (0);
}

static void			init_mandelbrot(t_mlx *smlx)
{
	t_fractal_thread	*arg[4];
	pthread_t			thread[4];
	int					i;

	i = 0;
	while (i < 4)
	{
		arg[i] = (t_fractal_thread*)malloc(sizeof(t_fractal_thread));
		arg[i]->smlx = smlx;
		if (i == 0 || i == 2)
		{
			arg[i]->pix_start[0] = 0;
			arg[i]->pix_end[0] = WIN_WIDTH / 2;
		}
		else
		{
			arg[i]->pix_start[0] = WIN_WIDTH / 2;
			arg[i]->pix_end[0] = WIN_WIDTH;
		}
		if (i == 2 || i == 3)
		{
			arg[i]->pix_start[1] = WIN_HEIGHT / 2;
			arg[i]->pix_end[1] = WIN_HEIGHT;
		}
		else
		{
			arg[i]->pix_start[1] = 0;
			arg[i]->pix_end[1] = WIN_HEIGHT / 2;
		}
		pthread_create(&thread[i], NULL, draw_mandelbrot, arg[i]);
		pthread_join(thread[i], NULL);
		free(arg[i]);
		i++;
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
		init_mandelbrot(smlx);
		mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
	}
	return (0);
}

void				fr_mandelbrot(t_mlx *smlx)
{
	smlx->offset_x = -250.0;
	smlx->offset_y = 0.0;
	smlx->zoom = 400.0;
	init_mandelbrot(smlx);
	mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
	mlx_hook(smlx->win, 2, 0, keyevent, (void*)smlx);
}
