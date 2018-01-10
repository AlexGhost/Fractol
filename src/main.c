/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:34:34 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/10 15:06:17 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		write_usage(void)
{
	ft_putendl("usage: ./fractol <mode>");
	ft_putendl("\tmode 1 : Mandelbrot");
	ft_putendl("\tmode 2 : Julia");
	ft_putendl("\tmode 3 : BurningShip");
	exit(0);
}

int				main(int ac, char **av)
{
	int mode;

	if (ac != 2)
		write_usage();
	mode = -1;
	if (ft_isdigit(av[1][0]) == 1)
		mode = ft_atoi(av[1]);
	if (mode != MANDELBROT && mode != JULIA && mode != SHIP && mode != COLOR \
			&& mode != PONG && mode != KEYPONG)
		write_usage();
	ft_putendl("--- Welcome to Fractolol ---");
	if (mode == MANDELBROT)
		ft_putendl("Mandelbrot");
	else if (mode == JULIA)
		ft_putendl("Julia");
	else if (mode == SHIP)
		ft_putendl("BurningShip");
	else if (mode == COLOR)
		ft_putendl("Colormania");
	else if (mode == PONG)
		ft_putendl("Pong");
	else if (mode == KEYPONG)
		ft_putendl("Key Pong");
	fr_create_window(mode);
	return (0);
}
