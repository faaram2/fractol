/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeganya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:51:53 by ayeganya          #+#    #+#             */
/*   Updated: 2024/06/06 15:04:55 by ayeganya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_data data);
int		mandelbrot(long double r, long double i);
int		julia(t_data data, long double r, long double i);
int		burning_ship(long double r, long double i);

int	cancel(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	exit (0);
}

void	img_pixel_put(t_img img, int x, int y, int color)
{
	void	*ptr;

	ptr = img.addr + (img.bpp * x) / 8 + img.line_len * y;
	*(int *)ptr = color;
}

int	color_gen(int tmp, int variant)
{
	if (variant == 0)
		return (WHITE - ((tmp << 12) + ((tmp % 8) << 20) + ((tmp % 3) << 4)));
	else if (variant == 1)
		return (WHITE - ((tmp << 13) + ((tmp % 40) << 18) + ((tmp % 40) << 3)));
	else if (variant == 2)
		return (WHITE - ((tmp << 16) + ((tmp % 40) << 9) + ((tmp % 40) << 3)));
	else if (variant == 3)
		return (WHITE - ((tmp << 16) + ((tmp % 40) << 10) + ((tmp % 40) << 3)));
	else if (variant == 4)
		return (WHITE - ((tmp << 16) + ((tmp % 40) << 10) + ((tmp % 40) << 5)));
	else if (variant == 5)
		return (WHITE - ((tmp << 16) + ((tmp % 20) << 10) + ((tmp % 20) << 5)));
	else if (variant == 6)
		return (WHITE - ((tmp << 10) + ((tmp % 3) << 21) + ((tmp % 3) << 3)));
	else
		return (WHITE - ((tmp << 13) + ((tmp % 7) << 21) + ((tmp % 3) << 3)));
}

int	fract_type(t_data data, long double r, long double i)
{
	if (data.fract_type == MANDELBROT)
		return (mandelbrot(r, i));
	else if (data.fract_type == JULIA)
		return (julia(data, r, i));
	else if (data.fract_type == BURN_SHIP)
		return (burning_ship(r, i));
	else
		return (-1);
}

int	kb_keys(int key, t_data *data)
{
	if (data->block == 1)
		return (0);
	data->block = 1;
	if (key == 123)
		data->cboard.r = data->cboard.r - data->cboard.size * SHIFT / WIN_WDT;
	else if (key == 124)
		data->cboard.r = data->cboard.r + data->cboard.size * SHIFT / WIN_WDT;
	else if (key == 125)
		data->cboard.i = data->cboard.i - data->cboard.size * SHIFT / WIN_WDT;
	else if (key == 126)
		data->cboard.i = data->cboard.i + data->cboard.size * SHIFT / WIN_WDT;
	else if (key == 49)
	{
		if (data->col_schm < 7)
			data->col_schm++;
		else
			data->col_schm = 0;
	}
	else if (key == 53)
		cancel(data);
	render(*data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, \
			0, 0);
	data->block = 0;
	return (0);
}
