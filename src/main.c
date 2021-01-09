/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:16:44 by skaren            #+#    #+#             */
/*   Updated: 2020/02/21 05:33:36 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		set_default(t_fractol *data)
{
	data->zoom = 1.0f;
	if (!(data->mlx_p = mlx_init()))
		error();
	if (!(data->win_p = mlx_new_window(data->mlx_p, 600, 600, "fractol")))
		error();
	if (!(data->img_ptr = mlx_new_image(data->mlx_p, 600, 600)))
		error();
	if (!(data->img_data = (int *)mlx_get_data_addr(data->img_ptr,
		&data->bpp, &data->size_line, &data->endian)))
		error();
	data->c_1 = 255;
	data->c_2 = 255;
	data->c_3 = 255;
	data->w = 600;
	data->h = 600;
}

void		error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int			loop_hook(t_fractol *data)
{
	data->fractal_fun(data);
	return (0);
}

void		check_arg(char *name_fractol)
{
	int		flag;

	flag = 0;
	if (ft_strequ(name_fractol, "Mandelbrot"))
		flag = 1;
	else if (ft_strequ(name_fractol, "Julia"))
		flag = 1;
	else if (ft_strequ(name_fractol, "Mandelbar"))
		flag = 1;
	else if (ft_strequ(name_fractol, "Burning_Ship"))
		flag = 1;
	else if (ft_strequ(name_fractol, "Perpendicular_Buffalo"))
		flag = 1;
	if (flag == 0)
	{
		write(1, "usage: ./fractol Julia\n", 23);
		write(1, "usage: ./fractol Mandelbrot\n", 28);
		write(1, "usage: ./fractol Mandelbar\n", 27);
		write(1, "usage: ./fractol Burning_Ship\n", 30);
		write(1, "usage: ./fractol Perpendicular_Buffalo\n", 39);
		exit(0);
	}
}

int			main(int a, char **b)
{
	t_fractol	*data;

	if (a == 2)
	{
		check_arg(b[1]);
		if (!(data = (t_fractol*)malloc(sizeof(t_fractol))))
			error();
		ft_bzero(data, sizeof(t_fractol));
		set_default(data);
		connect_point(data, b[1]);
		mlx_loop_hook(data->mlx_p, loop_hook, data);
		hook(data);
		mlx_loop(data->mlx_p);
	}
	else
	{
		write(1, "usage: ./fractol Julia\n", 23);
		write(1, "usage: ./fractol Mandelbrot\n", 28);
		write(1, "usage: ./fractol Mandelbar\n", 27);
		write(1, "usage: ./fractol Burning_Ship\n", 30);
		write(1, "usage: ./fractol Perpendicular_Buffalo\n", 39);
	}
	return (0);
}
