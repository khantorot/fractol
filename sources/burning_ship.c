/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 08:35:02 by glychest          #+#    #+#             */
/*   Updated: 2020/02/17 17:14:20 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		burning_ship(t_data *data)
{
	int		i;
	t_cx	z;

	i = 0;
	z = init_cx(data->c.re, data->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && i < data->max_i)
	{
		z = init_cx(pow(z.re, 2.0) - pow(z.im, 2.0)
			+ data->c.re, -2.0 * fabs(z.re * z.im) + data->c.im);
		i++;
	}
	return (i);
}
