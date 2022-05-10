/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:32:25 by glychest          #+#    #+#             */
/*   Updated: 2020/02/18 13:57:13 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		(*check_fractol(char *title))(t_data *data)
{
	size_t				i;
	int					(*fractol)(t_data *data);
	static t_fractol	fractols[] = {
		{ "-m", &mandelbrot },
		{ "-j", &julia },
		{ "-b", &burning_ship},
		{ "-c", &cell},
		{ "-p", &celtic}
	};

	i = 0;
	fractol = NULL;
	while (i < (sizeof(fractols) / sizeof(t_fractol)))
	{
		if (ft_strequ(title, fractols[i].title))
			fractol = fractols[i].fractol;
		i++;
	}
	return (fractol);
}

static	t_img	*init_img(void *mlx)
{
	t_img		*img;

	if (!(img = (t_img *)ft_memalloc(sizeof(t_img))))
		ft_error("Image initialization error");
	if (!(img->img = mlx_new_image(mlx, WIDTH, HEIGHT)))
		ft_error("Image initialization error");
	img->data_addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->size_line, &img->endian);
	return (img);
}

static	t_data	*init_data(char *title, void *mlx)
{
	t_data		*data;

	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		ft_error("Fract_ol initialization error");
	data->mlx = mlx;
	if (!(data->win = mlx_new_window(mlx, WIDTH, HEIGHT, title)))
		ft_error("Window initialization error");
	data->img = init_img(mlx);
	default_tune(data);
	data->julia_view = false;
	if (!(data->fractol = check_fractol(title)))
		ft_error("Fract_ol name error");
	mlx_hook(data->win, 4, 0, zoom, data);
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 17, 0, close_win, data);
	if (ft_strequ(title, "-j"))
		mlx_hook(data->win, 6, 0, julia_motion, data);
	return (data);
}

void			build(int count, char **titles)
{
	t_data		*data[5];
	void		*mlx;
	int			i;

	i = 0;
	mlx = mlx_init();
	while (i < count - 1)
	{
		data[i] = init_data(titles[i], mlx);
		draw(data[i]);
		i++;
	}
	mlx_loop(mlx);
}

int				main(int argc, char **argv)
{
	int i;

	if (argc > 1 && argc < 7)
	{
		i = 1;
		while (i < argc)
		{
			if (check_fractol(argv[i]) == 0)
				break ;
			i++;
		}
		build(argc, &argv[1]);
	}
	instruct();
	return (0);
}
