/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:34:50 by glychest          #+#    #+#             */
/*   Updated: 2020/02/18 16:26:21 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH				1300
# define HEIGHT 			1300
# define THREADS			5

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>

# define KEY_SCROLL_UP		4
# define KEY_SCROLL_DOWN	5
# define KEY_SPACE			49
# define KEY_R				15
# define KEY_ESC			53
# define KEY_PLUS			69
# define KEY_MINUS			78
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_C				8
# define KEY_D 				2

typedef struct				s_img
{
	void					*img;
	char					*data_addr;
	int						bits_per_pixel;
	int						size_line;
	int						endian;
}							t_img;

typedef struct				s_cx
{
	double					re;
	double					im;
}							t_cx;

typedef	struct				s_color
{
	int						channel[4];
}							t_color;

typedef struct				s_data
{
	void					*mlx;
	void					*win;
	t_img					*img;
	int						(*fractol)(struct s_data *data);
	t_cx					min;
	t_cx					max;
	t_cx					bond;
	t_cx					c;
	t_cx					j;
	int						max_i;
	t_bool					julia_view;
	int						start;
	int						finish;
	int						color_id;
	t_color					color;
}							t_data;

typedef struct				s_fractol
{
	char					*title;
	int						(*fractol)(t_data *data);
}							t_fractol;

int							mandelbrot(t_data *data);
int							julia(t_data *data);
int							julia_motion(int x, int y, t_data *data);
int							burning_ship(t_data *data);
int							cell(t_data *data);
int							celtic(t_data *data);

t_cx						init_cx(double re, double im);
void						default_tune(t_data *data);
int							key_press(int key, t_data *data);
int							zoom(int button, int x, int y, t_data *data);
void						draw(t_data *data);

void						change_color(t_data *data);
int							julia_motion(int x, int y, t_data *data);
void						move(int key, t_data *data);
void						tune_max_i(int key, t_data *data);
void						delay(t_data *data);

double						ft_double_abs(double nb);
int							close_win(void *param);
void						instruct(void);

#endif
