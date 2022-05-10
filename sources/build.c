/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:29:40 by glychest          #+#    #+#             */
/*   Updated: 2020/02/18 16:12:25 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			default_tune(t_data *data)
{
	data->max_i = 50;
	data->min = init_cx(-2.0, -2.0);
	data->max.re = 2.0;
	data->max.im = data->min.im +
		(data->max.re - data->min.re) * HEIGHT / WIDTH;
	data->j = init_cx(-0.4, 0.6);
}

t_cx			init_cx(double re, double im)
{
	t_cx	cx;

	cx.re = re;
	cx.im = im;
	return (cx);
}

int				key_press(int key, t_data *data)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_R)
	{
		default_tune(data);
		draw(data);
	}
	else if (key == KEY_MINUS || key == KEY_PLUS)
		tune_max_i(key, data);
	else if (key == KEY_DOWN || key == KEY_LEFT
		|| key == KEY_RIGHT || key == KEY_UP)
		move(key, data);
	else if (key == KEY_SPACE)
		data->julia_view = !data->julia_view;
	else if (key == KEY_C)
		change_color(data);
	else if (key == KEY_D)
		delay(data);
	return (0);
}

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

int				zoom(int button, int x, int y, t_data *data)
{
	t_cx		mouse;
	double		interpolation;
	double		zoom;

	if ((button == KEY_SCROLL_UP || button == KEY_SCROLL_DOWN))
	{
		mouse = init_cx(
			(double)x / (WIDTH / (data->max.re - data->min.re))
				+ data->min.re,
			(double)y / (HEIGHT / (data->max.im - data->min.im))
				* -1 + data->max.im);
		if (button == KEY_SCROLL_UP)
			zoom = 0.80;
		else
			zoom = 1.20;
		interpolation = 1.0 / zoom;
		data->min.re = interpolate(mouse.re, data->min.re, interpolation);
		data->min.im = interpolate(mouse.im, data->min.im, interpolation);
		data->max.re = interpolate(mouse.re, data->max.re, interpolation);
		data->max.im = interpolate(mouse.im, data->max.im, interpolation);
		draw(data);
	}
	return (0);
}
