/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_multithread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:14:56 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/10 16:38:54 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			fr_create_threads(t_mlx *smlx)
{
	t_thread	sthreads[NB_THREADS];
	pthread_t	t[NB_THREADS];
	int			i;
	float		length_threads;

	i = -1;
	length_threads = (WIN_WIDTH * WIN_HEIGHT) / NB_THREADS;
	while (++i < NB_THREADS || !(i = -1))
	{
		sthreads[i].smlx = smlx;
		sthreads[i].pix_start = i * length_threads;
		sthreads[i].pix_end = sthreads[i].pix_start + length_threads;
		if (smlx->mode == MANDELBROT)
			pthread_create(&t[i], NULL, fr_draw_mandelbrot, \
					(void*)&sthreads[i]);
		else if (smlx->mode == JULIA)
			pthread_create(&t[i], NULL, fr_draw_julia, \
					(void*)&sthreads[i]);
		else if (smlx->mode == SHIP)
			pthread_create(&t[i], NULL, fr_draw_burningship, \
					(void*)&sthreads[i]);
	}
	while (++i < NB_THREADS)
		pthread_join(t[i], NULL);
}
