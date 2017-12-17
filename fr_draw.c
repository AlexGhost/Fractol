/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:52:07 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/17 18:12:17 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			fr_putpixel(int *imgstr, int x, int y, int color)
{
	int pos;

	pos = y + (x * WIN_WIDTH);
	imgstr[pos] = color;
}
