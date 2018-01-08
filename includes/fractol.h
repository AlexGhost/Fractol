/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:22:05 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/08 16:20:03 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

# define WIN_WIDTH 1400
# define WIN_HEIGHT 1000
# define NB_ITERATION 50
# define BUTTON_ESCAPE 53
# define BUTTON_W 13
# define BUTTON_D 2
# define BUTTON_S 1
# define BUTTON_A 0
# define BUTTON_Q 12
# define BUTTON_E 14
# define BUTTON_B 11
# define BUTTON_C 8
# define BUTTON_ARROW_UP 126
# define BUTTON_ARROW_RIGHT 124
# define BUTTON_ARROW_DOWN 125
# define BUTTON_ARROW_LEFT 123
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_WHEEL_UP 5
# define MOUSE_WHEEL_DOWN 4

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*imgstr;
	int				actual_color;
	int				mode;
	int				block_view;
	float			varx;
	float			vary;
	float			offset_x;
	float			offset_y;
	float			zoom;
}					t_mlx;

typedef struct		s_mandelbrot
{
	int				actual_pix;
	float			iter;
	float			pix[2];
	float			z[2];
	float			tmp[3];
}					t_mandelbrot;

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
void				fr_colormania(t_mlx *smlx);
void				fr_mandelbrot(t_mlx *smlx);
void				fr_julia(t_mlx *smlx);
void				fr_pong(t_mlx *smlx);
void				fr_keypong(t_mlx *smlx);
void				fr_draw_julia(t_mlx *smlx);
int					fr_keyevent_julia(int keycode, t_mlx *smlx);
void				fr_change_color(int *color);

#endif
