/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:16:44 by skaren            #+#    #+#             */
/*   Updated: 2020/02/21 01:56:35 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	i_comp(float re, float im)
{
	t_complex complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void		set_color(t_fractol *data, int iteration, int max_iteration)
{
	float	t;

	t = (float)iteration / (float)max_iteration;
	data->color = 0;
	data->color |= ((int)(9 * (1 - t) * pow(t, 3) * data->c_1)) << 8 * 2;
	data->color |= ((int)(15 * pow((1 - t), 2) * pow(t, 2) * data->c_2)) << 8;
	data->color |= (int)(8.5 * pow((1 - t), 3) * t * data->c_3);
}

float		range_change(float zoom_factor, int value)
{
	return ((float)value * ((2 / zoom_factor) -
		(-2 / zoom_factor))) / 600 + (-2 / zoom_factor);
}

void		connect_point(t_fractol *data, char *name_fractol)
{
	if (ft_strequ(name_fractol, "Mandelbrot"))
		data->fractal_fun = &mandelbrot;
	else if (ft_strequ(name_fractol, "Julia"))
		data->fractal_fun = &julia;
	else if (ft_strequ(name_fractol, "Mandelbar"))
		data->fractal_fun = &mandelbar;
	else if (ft_strequ(name_fractol, "Burning_Ship"))
		data->fractal_fun = &burning_ship;
	else if (ft_strequ(name_fractol, "Perpendicular_Buffalo"))
		data->fractal_fun = &perp_buff;
}
