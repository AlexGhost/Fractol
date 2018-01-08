/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:34:34 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/08 17:28:01 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		write_usage(void)
{
	ft_putendl("usage: ./fractol <mode>");
	ft_putendl("\tmode 0 : Colormania");
	ft_putendl("\tmode 1 : Mandelbrot");
	ft_putendl("\tmode 2 : Julia");
	ft_putendl("\tmode 3 : BurningShip");
	ft_putendl("\tmode 4 : Pong");
	ft_putendl("\tmode 5 : KeyPong");
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
	if (mode < 0 || mode > 5)
		write_usage();
	ft_putendl("--- Welcome to Fractolol ---");
	if (mode == 0)
		ft_putendl("Colormania");
	else if (mode == 1)
		ft_putendl("Mandelbrot");
	else if (mode == 2)
		ft_putendl("Julia");
	else if (mode == 3)
		ft_putendl("BurningShip");
	else if (mode == 4)
		ft_putendl("Pong!");
	else if (mode == 5)
		ft_putendl("Key Pong!");
	fr_create_window(mode);
	return (0);
}
