/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:16:44 by skaren            #+#    #+#             */
/*   Updated: 2020/02/21 01:56:35 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		burning_ship(t_fractol *data)
{
	int				xy[2];
	int				it_m[2];
	t_complex_all	a;

	a.min = i_comp(-2.0, -2.0);
	a.max.re = 2.0;
	a.max.im = a.min.im + (a.max.re - a.min.re) * data->h / data->w;
	burning_ship2(data, &a, xy, it_m);
}

void		burning_ship2(t_fractol *data, t_complex_all *a, int xy[2],
							int it_m[2])
{
	it_m[1] = 50;
	xy[1] = -1;
	while (++xy[1] < data->h)
	{
		a->c.im = range_change(data->zoom, xy[1]) + data->move_y;
		xy[0] = -1;
		while (++xy[0] < data->w)
		{
			a->c.re = range_change(data->zoom, xy[0]) + data->move_x;
			a->z = i_comp(a->c.re, a->c.im);
			it_m[0] = 0;
			while (pow(a->z.re, 2.0) + pow(a->z.im, 2.0) <= 4
				&& it_m[0] < it_m[1])
			{
				a->z = i_comp(pow(a->z.re, 2.0) - pow(a->z.im, 2.0) + a->c.re,
					-2.0 * fabs(a->z.re * a->z.im) + a->c.im);
				it_m[0]++;
			}
			set_color(data, it_m[0], it_m[1]);
			data->img_data[xy[1] * data->h + xy[0]] = data->color;
		}
	}
	mlx_put_image_to_window(data->mlx_p, data->win_p, data->img_ptr, 0, 0);
}
