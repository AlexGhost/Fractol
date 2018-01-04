/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_keypong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:01:14 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/04 13:07:39 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void			drawball(t_pong *pong, int x, int y, int color)
{
	int i;
	int j;

	j = y - 10;
	while (j < 20 + (y - 10))
	{
		i = x - 10;
		while (i < 20 + (x - 10))
		{
			fr_putpixel(pong->smlx->imgstr, i, j, color);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(pong->smlx->mlx, pong->smlx->win, pong->smlx->img, \
			0, 0);
}

static int			mouseevent(int button, long x, long y, t_pong *pong)
{
	ft_putstr("mouse x: ");
	ft_putnbr(x);
	ft_putstr(" y: ");
	ft_putnbr(y);
	ft_putchar('\n');
	return (0);
}

static int			looppong(t_pong *pong)
{
	pong->d_x = 0;
	pong->d_y = 0;
	return (0);
}

static int			keyevent(int keycode, t_pong *pong)
{
	if (keycode == BUTTON_ESCAPE)
	{
		ft_putendl("fractol shutting down");
		exit(0);
	}
	else if (keycode == BUTTON_ARROW_UP && pong->bally > 15)
		pong->d_y = -1;
	else if (keycode == BUTTON_ARROW_DOWN && pong->bally < WIN_HEIGHT - 15)
		pong->d_y = 1;
	else if (keycode == BUTTON_ARROW_LEFT && pong->ballx > 15)
		pong->d_x = -1;
	else if (keycode == BUTTON_ARROW_RIGHT && pong->ballx < WIN_WIDTH - 15)
		pong->d_x = 1;
	drawball(pong, pong->ballx, pong->bally, 0x00FFFFFF);
	drawball(pong, pong->ballx + pong->d_x, pong->bally + pong->d_y, \
			0x00FF0000);
	pong->ballx += pong->d_x;
	pong->bally += pong->d_y;
	if (pong->bally > WIN_HEIGHT - 15 || pong->bally < 15)
		pong->d_y = -pong->d_y;
	if (pong->ballx > WIN_WIDTH - 15 || pong->ballx < 15)
		pong->d_x = -pong->d_x;
	return (0);
}

void				fr_keypong(t_mlx *smlx)
{
	t_pong		*pong;

	pong = (t_pong*)malloc(sizeof(t_pong));
	pong->ballx = 50;
	pong->bally = 50;
	pong->d_x = 0;
	pong->d_y = 0;
	pong->smlx = smlx;
	drawball(pong, pong->ballx + pong->d_x, pong->bally + pong->d_y, \
			0x00FF0000);
	mlx_loop_hook(smlx->mlx, looppong, (void*)pong);
	mlx_hook(smlx->win, 2, 0, keyevent, (void*)pong);
	mlx_hook(smlx->win, 6, 6, mouseevent, (void*)pong);
}
