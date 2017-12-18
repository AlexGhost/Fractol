/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:34:34 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/18 15:47:00 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		write_usage(void)
{
	ft_putendl("usage: ./fractol <mode>");
	ft_putendl("\tmode 0 : Colormania");
	ft_putendl("\tmode 1 : Mandelbrot");
	ft_putendl("\tmode 4 : Pong");
	exit(0);
}

int				main(int ac, char **av)
{
	int mode;

	if (ac != 2)
		write_usage();
	else
		mode = ft_atoi(av[1]);
	if (mode < 0 || mode > 4)
		write_usage();
	else
	{
		ft_putendl("--- Welcome to Fractolol ---");
		if (mode == 0)
			ft_putendl("Colormania");
		else if (mode == 1)
			ft_putendl("Mandelbrot");
		else if (mode == 4)
			ft_putendl("Pong!");
		fr_create_window(mode);
	}
	return (0);
}
