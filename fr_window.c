/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 15:29:23 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/17 18:45:00 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

static int		colormania(t_mlx *smlx)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			fr_putpixel(smlx->imgstr, x, y, smlx->actual_color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
	smlx->actual_color += sin(smlx->actual_color += 0x00010105);
	return (0);
}

void			fr_create_window(void)
{
	t_mlx		smlx;
	t_img		i;

	smlx.mlx = mlx_init();
	smlx.win = mlx_new_window(smlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fractolol");
	smlx.img = mlx_new_image(smlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	smlx.imgstr = (int*)mlx_get_data_addr(smlx.img, &i.bpp, &i.s_l, &i.endian);
	smlx.actual_color = 0;
	mlx_key_hook(smlx.win, keyevent, 0);
	mlx_hook(smlx.win, 17, 17, exitfractol, 0);
	mlx_loop_hook(smlx.mlx, colormania, (void*) &smlx);
	mlx_loop(smlx.mlx);
}
