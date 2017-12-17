/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:34:34 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/17 19:02:35 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		write_usage(void)
{
	ft_putendl("usage: ./fractol <mode>");
	ft_putendl("\tmode 1 : Mandelbrot");
	exit(0);
}

int				main(int ac, char **av)
{
	int mode;

	if (ac != 2)
		write_usage();
	else
		mode = ft_atoi(av[1]);
	if (mode != 1)
		write_usage();
	else
	{
		ft_putendl("--- Welcome to Fractolol ---");
		fr_create_window();
	}
	return (0);
}
