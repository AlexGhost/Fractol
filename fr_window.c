/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 15:29:23 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/17 16:15:49 by acourtin         ###   ########.fr       */
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
	if (keycode == 53)
		exitfractol();
	return (0);
}

void			fr_create_window(void)
{
	t_mlx		smlx;
	t_img		img;

	smlx.mlx = mlx_init();
	smlx.win = mlx_new_window(smlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fractolol");
	smlx.img = mlx_new_image(smlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	smlx.img_str = (int*) mlx_get_data_addr(smlx.img, &img.bpp, &img.s_l, &img.endian);
	smlx.img_str[0] = 0x00FFFFFF;
	smlx.img_str[1] = 0x00FFFFFF;
	smlx.img_str[2] = 0x00FFFFFF;
	smlx.img_str[3] = 0x00FFFFFF;
	mlx_put_image_to_window(smlx.mlx, smlx.win, smlx.img, 0, 0);
	mlx_key_hook(smlx.win, keyevent, 0);
	mlx_hook(smlx.win, 17, 17, exitfractol, 0);
	mlx_loop(smlx.mlx);
}
