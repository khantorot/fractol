/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:27:30 by glychest          #+#    #+#             */
/*   Updated: 2020/02/18 11:38:04 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	instruct(void)
{
	ft_putendl("Usage: ./fractol [-symbol]");
	ft_putendl(" ");
	ft_putendl("<List of fractals>");
	ft_putendl("-m -> Mandelbrot");
	ft_putendl("-j -> Julia");
	ft_putendl("-b -> Burning Ship");
	ft_putendl("-p -> Perpendicular Celtic");
	ft_putendl("-c -> Cell");
	ft_putendl(" ");
	ft_putendl("Also you can open all of them [./fractol -m -j -b -p -c]");
}

int		close_win(void *param)
{
	(void)param;
	exit(0);
}

double	ft_double_abs(double nb)
{
	return (nb < 0 ? nb : -nb);
}
