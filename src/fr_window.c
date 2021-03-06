/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 15:29:23 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/10 15:07:27 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		exitfractol(void)
{
	ft_putendl("fractol shutting down");
	exit(0);
	return (0);
}

static int		keyevent(int keycode)
{
	ft_putstr("Button pressed : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == BUTTON_ESCAPE)
		exitfractol();
	return (0);
}

static void		fractol_init(t_mlx *smlx, t_img *i, int mode)
{
	smlx->mlx = mlx_init();
	smlx->win = mlx_new_window(smlx->mlx, WIN_WIDTH, WIN_HEIGHT, "fractolol");
	smlx->img = mlx_new_image(smlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	smlx->imgstr = (int*)mlx_get_data_addr(smlx->img, &i->bpp, &i->s_l, \
			&i->endian);
	smlx->actual_color = 0x00FFFFFF;
	smlx->mode = mode;
}

void			fr_clear_window(t_mlx *smlx, int color)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			smlx->imgstr[x + (y * WIN_WIDTH)] = color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
}

void			fr_create_window(int mode)
{
	t_mlx		smlx;
	t_img		i;

	fractol_init(&smlx, &i, mode);
	mlx_key_hook(smlx.win, keyevent, 0);
	mlx_hook(smlx.win, 17, 17, exitfractol, 0);
	if (mode == MANDELBROT)
		fr_mandelbrot(&smlx);
	else if (mode == JULIA)
		fr_julia(&smlx);
	else if (mode == SHIP)
		fr_burningship(&smlx);
	else if (mode == COLOR)
		fr_colormania(&smlx);
	else if (mode == PONG)
		fr_pong(&smlx);
	else if (mode == KEYPONG)
		fr_keypong(&smlx);
	mlx_loop(smlx.mlx);
}
