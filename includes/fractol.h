/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:22:05 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/05 20:20:48 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>

# define WIN_WIDTH 1400
# define WIN_HEIGHT 1000
# define NB_ITERATION 256
# define NB_THREADS 56
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

typedef struct		s_fractal_thread
{
	t_mlx			*smlx;
	float			pix_start;
	float			pix_end;
}					t_fractal_thread;

typedef struct		s_mandelbrot
{
	int				pix[2];
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
void				fr_pong(t_mlx *smlx);
void				fr_keypong(t_mlx *smlx);

#endif
