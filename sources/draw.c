/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:25:54 by glychest          #+#    #+#             */
/*   Updated: 2020/02/18 16:30:33 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_color	get_color(int i, t_data *data)
{
	t_color	color;
	double	t;

	t = (double)i / data->max_i;
	color.channel[0] = (int)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[(0 + data->color_id) % 3 + 1] =
		(int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[(1 + data->color_id) % 3 + 1] =
		(int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[(2 + data->color_id) % 3 + 1] =
		(int)(9 * (1 - t) * pow(t, 3) * 255);
	return (color);
}

static void		put_pixel(t_data *data, int x, int y, t_color color)
{
	int	i;

	i = (x * data->img->bits_per_pixel / 8) + (y * data->img->size_line);
	data->img->data_addr[i] = color.channel[3];
	data->img->data_addr[++i] = color.channel[2];
	data->img->data_addr[++i] = color.channel[1];
	data->img->data_addr[++i] = color.channel[0];
}

static	void	draw_piece(t_data *data)
{
	int			x;
	int			y;

	y = data->start;
	while (y < data->finish)
	{
		data->c.im = data->max.im - y * data->bond.im;
		x = 0;
		while (x < WIDTH)
		{
			data->c.re = data->min.re + x * data->bond.re;
			put_pixel(data, x, y, get_color(data->fractol(data), data));
			x++;
		}
		y++;
	}
}

void			draw(t_data *data)
{
	pthread_t	threads[THREADS];
	t_data		fractols[THREADS];
	int			i;

	data->bond = init_cx(
		(data->max.re - data->min.re) / (WIDTH + 1),
		(data->max.im - data->min.im) / (HEIGHT - 1));
	i = 0;
	while (i < THREADS)
	{
		fractols[i] = *data;
		fractols[i].start = i * (HEIGHT / THREADS);
		fractols[i].finish = (i + 1) * (HEIGHT / THREADS);
		if (pthread_create(&threads[i], NULL,
			(void *(*)(void *))draw_piece, &fractols[i]))
			ft_error("Threads error");
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			ft_error("Threads error");
	mlx_put_image_to_window(data->mlx, data->win,
		data->img->img, 0, 0);
}
