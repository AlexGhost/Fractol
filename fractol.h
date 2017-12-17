/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:22:05 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/17 16:12:36 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*img_str;
}					t_mlx;

typedef struct		s_img
{
	int				bpp;
	int				s_l;
	int				endian;
}					t_img;

void				fr_create_window(void);

#endif
