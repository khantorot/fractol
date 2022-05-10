/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:31:09 by glychest          #+#    #+#             */
/*   Updated: 2020/02/18 14:21:53 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		tune_max_i(int key, t_data *data)
{
	if (key == KEY_PLUS)
	{
		if (data->max_i < 50)
			data->max_i += 1;
		else if (data->max_i < 1000000000)
			data->max_i = (int)(data->max_i * 1.05);
	}
	if (key == KEY_MINUS)
	{
		if (data->max_i > 100)
			data->max_i = (int)(data->max_i * 0.95);
		else if (data->max_i > 1)
			data->max_i -= 1;
	}
	draw(data);
}

void		move(int key, t_data *data)
{
	t_cx	delta;

	delta = init_cx(ft_double_abs(data->max.re - data->min.re),
		ft_double_abs(data->max.im - data->min.im));
	if (key == KEY_LEFT)
	{
		data->min.re -= delta.re * 0.05;
		data->max.re -= delta.re * 0.05;
	}
	else if (key == KEY_RIGHT)
	{
		data->min.re += delta.re * 0.05;
		data->max.re += delta.re * 0.05;
	}
	else if (key == KEY_UP)
	{
		data->min.im += delta.im * 0.05;
		data->max.im += delta.im * 0.05;
	}
	else if (key == KEY_DOWN)
	{
		data->min.im -= delta.im * 0.05;
		data->max.im -= delta.im * 0.05;
	}
	draw(data);
}

int			julia_motion(int x, int y, t_data *data)
{
	if (!data->julia_view)
	{
		data->j = init_cx(
			4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		draw(data);
	}
	return (0);
}

void		change_color(t_data *data)
{
	data->color_id = (data->color_id + 1) % 3;
	draw(data);
}

void		delay(t_data *data)
{
	draw(data);
	usleep(1000);
}
