/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:46:52 by glychest          #+#    #+#             */
/*   Updated: 2020/02/17 17:13:54 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		celtic(t_data *data)
{
	int		i;
	t_cx	z;

	i = 0;
	z = init_cx(data->c.re, data->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && i < data->max_i)
	{
		z = init_cx(fabs(pow(z.re, 2.0) - pow(z.im, 2.0))
			+ data->c.re, -2.0 * fabs(z.re) * z.im + data->c.im);
		i++;
	}
	return (i);
}
