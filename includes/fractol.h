/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:16:44 by skaren            #+#    #+#             */
/*   Updated: 2020/02/21 01:56:35 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdlib.h>

typedef struct	s_fractol
{
	int		w;
	int		h;
	float	zoom;
	int		color;
	int		x_jul;
	int		y_jul;
	float	move_x;
	float	move_y;
	int		c_1;
	int		c_2;
	int		c_3;
	void	*mlx_p;
	void	*win_p;
	int		bpp;
	int		size_line;
	int		endian;
	void	*img_ptr;
	int		*img_data;
	int		stop_jul;
	void	(*fractal_fun)(struct s_fractol *data);
}				t_fractol;

typedef struct	s_complex
{
	float		im;
	float		re;
}				t_complex;

typedef struct	s_complex_all
{
	t_complex	min;
	t_complex	max;
	t_complex	c;
	t_complex	z;
	t_complex	k;
}				t_complex_all;

void			mandelbrot(t_fractol *data);
void			mandelbrot2(t_fractol *data, t_complex_all *a, int xy[2],
							int it_m[2]);
void			perp_buff(t_fractol *data);
void			perp_buff2(t_fractol *data, t_complex_all *a, int xy[2],
							int it_m[2]);
void			burning_ship(t_fractol *data);
void			burning_ship2(t_fractol *data, t_complex_all *a, int xy[2],
								int it_m[2]);
void			julia(t_fractol *data);
void			julia2(t_fractol *data, t_complex_all *a, int xy[2],
							int it_m[2]);
void			mandelbar(t_fractol *data);
void			mandelbar2(t_fractol *data, t_complex_all *a, int xy[2],
							int it_m[2]);
void			hook(t_fractol *data);
int				loop_hook(t_fractol *data);
int				if_mouse_d_up(int key, int x, int y, t_fractol *data);
int				if_mouse(int x, int y, t_fractol *data);
int				if_esc_x(int key, t_fractol *data);
int				if_esc(int key, t_fractol *data);
void			error(void);
void			connect_point(t_fractol *data, char *name_fractol);
void			set_default(t_fractol *data);
t_complex		i_comp(float re, float im);
void			set_color(t_fractol *data, int iteration, int max_iteration);
float			range_change(float zoom_factor, int value);
void			check_arg(char *name_fractol);

#endif
