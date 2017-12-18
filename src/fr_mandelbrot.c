/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:33:55 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/18 14:46:32 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				fr_mandelbrot(t_mlx *smlx)
{
	fr_putpixel(smlx->imgstr, 1, 1, smlx->actual_color);
	mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
}
