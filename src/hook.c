/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:16:44 by skaren            #+#    #+#             */
/*   Updated: 2020/02/21 05:33:36 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		if_esc(int key, t_fractol *data)
{
	key == 16 && data->c_1 + 10 <= 255 ? data->c_1 += 10 : 0;
	key == 4 && data->c_1 - 10 >= 0 ? data->c_1 -= 10 : 0;
	key == 32 && data->c_2 + 10 <= 255 ? data->c_2 += 10 : 0;
	key == 38 && data->c_2 - 10 >= 0 ? data->c_2 -= 10 : 0;
	key == 34 && data->c_3 + 10 <= 255 ? data->c_3 += 10 : 0;
	key == 40 && data->c_3 - 10 >= 0 ? data->c_3 -= 10 : 0;
	key == 3 ? data->zoom += 100.0 : 0;
	key == 5 ? data->zoom += 1000.0 : 0;
	key == 0 ? data->move_x -= 0.1 / data->zoom : 0;
	key == 2 ? data->move_x += 0.1 / data->zoom : 0;
	key == 1 ? data->move_y += 0.1 / data->zoom : 0;
	key == 13 ? data->move_y -= 0.1 / data->zoom : 0;
	data = (t_fractol*)(void *)data;
	if (key == 53)
		exit(0);
	return (0);
}

int		if_esc_x(int key, t_fractol *data)
{
	data = (t_fractol*)(void *)data;
	if (key)
		exit(0);
	return (0);
}

int		if_mouse(int x, int y, t_fractol *data)
{
	if (data->stop_jul != 1)
	{
		data->x_jul = x;
		data->y_jul = y;
	}
	return (0);
}

int		if_mouse_d_up(int key, int x, int y, t_fractol *data)
{
	x = (int)x;
	y = (int)y;
	if (key == 4)
	{
		if (data->zoom >= 1.2)
			data->zoom -= 0.2;
	}
	else if (key == 5)
	{
		data->zoom += 0.2;
	}
	else if (key == 1)
	{
		if (data->stop_jul == 0)
			data->stop_jul = 1;
		else
			data->stop_jul = 0;
	}
	else if (key == 2)
		data->zoom = 1.0;
	return (0);
}

void	hook(t_fractol *data)
{
	mlx_hook(data->win_p, 2, 0, if_esc, (void *)data);
	mlx_hook(data->win_p, 4, 0, if_mouse_d_up, (void *)data);
	mlx_hook(data->win_p, 6, 0, if_mouse, (void *)data);
	mlx_hook(data->win_p, 17, 0, if_esc_x, (void *)data);
}
