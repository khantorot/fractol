/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:13:36 by glychest          #+#    #+#             */
/*   Updated: 2020/02/18 14:18:50 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia(t_data *data)
{
	int			i;
	t_cx		z;

	i = 0;
	z = init_cx(data->c.re, data->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && i < data->max_i)
	{
		z = init_cx(pow(z.re, 2.0) - pow(z.im, 2.0)
		+ data->j.re, 2.0 * z.re * z.im + data->j.im);
		i++;
	}
	return (i);
}
