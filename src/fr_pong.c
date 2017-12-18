/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_pong.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:45:16 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/18 16:51:31 by acourtin         ###   ########.fr       */
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

static int			looppong(t_pong *pong)
{
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

void				fr_pong(t_mlx *smlx)
{
	t_pong		*pong;

	pong = (t_pong*)malloc(sizeof(t_pong));
	pong->ballx = 50;
	pong->bally = 50;
	pong->d_x = 6;
	pong->d_y = 3;
	pong->smlx = smlx;
	mlx_loop_hook(smlx->mlx, looppong, (void*)pong);
}
