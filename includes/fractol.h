/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:22:05 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/04 19:03:27 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

# define WIN_WIDTH 1400
# define WIN_HEIGHT 800
# define NB_ITERATION 50
# define BUTTON_ESCAPE 53
# define BUTTON_W 13
# define BUTTON_D 2
# define BUTTON_S 1
# define BUTTON_A 0
# define BUTTON_Q 12
# define BUTTON_E 14
# define BUTTON_ARROW_UP 126
# define BUTTON_ARROW_RIGHT 124
# define BUTTON_ARROW_DOWN 125
# define BUTTON_ARROW_LEFT 123

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*imgstr;
	int				actual_color;
	int				mode;
	float			offset_x;
	float			offset_y;
	float			zoom;
}					t_mlx;

typedef struct		s_img
{
	int				bpp;
	int				s_l;
	int				endian;
}					t_img;

typedef struct		s_pong
{
	t_mlx			*smlx;
	int				ballx;
	int				bally;
	int				d_x;
	int				d_y;
}					t_pong;

void				fr_create_window(int mode);
void				fr_clear_window(t_mlx *smlx, int color);
void				fr_putpixel(int *imgstr, int x, int y, int color);
void				fr_colormania(t_mlx *smlx);
void				fr_mandelbrot(t_mlx *smlx);
void				fr_pong(t_mlx *smlx);
void				fr_keypong(t_mlx *smlx);

#endif
