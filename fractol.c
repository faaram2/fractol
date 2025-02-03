/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeganya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:27:49 by ayeganya          #+#    #+#             */
/*   Updated: 2024/06/06 15:17:06 by ayeganya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		cancel(t_data *data);
void	img_pixel_put(t_img img, int x, int y, int color);
int		color_gen(int tmp, int variant);
int		fract_type(t_data data, long double r, long double i);
int		kb_keys(int key, t_data *data);

void	render(t_data data)
{
	long double	r;
	long double	i;
	int			x;
	int			y;
	int			temp;

	i = data.cboard.i;
	y = 0;
	while (y < WIN_HGT)
	{
		x = 0;
		r = data.cboard.r;
		while (x < WIN_WDT)
		{
			temp = fract_type(data, r, i);
			if (temp == -1)
				img_pixel_put(data.img, x, y, BLACK);
			else
				img_pixel_put(data.img, x, y, color_gen(temp, data.col_schm));
			r += data.cboard.size / WIN_WDT;
			x++;
		}
		i -= data.cboard.size / WIN_HGT;
		y++;
	}
}

int	zoom(int button, int x, int y, t_data *data)
{
	if (x > WIN_WDT || x < 0 || y > WIN_HGT || y < 0 || data->block == 1)
		return (0);
	data->block = 1;
	if (button == 4)
	{
		data->cboard.r = data->cboard.r + data->cboard.size * ((long double)x \
				/ WIN_WDT - 1.0 / (2 * ZOOM));
		data->cboard.i = data->cboard.i - data->cboard.size * ((long double)y \
				/ WIN_HGT - 1.0 / (2 * ZOOM));
		data->cboard.size = data->cboard.size / ZOOM;
	}
	else if (button == 5)
	{
		data->cboard.r = data->cboard.r - (ZOOM / 2.0 -0.5) * data->cboard.size;
		data->cboard.i = data->cboard.i + (ZOOM / 2.0 -0.5) * data->cboard.size;
		data->cboard.size = data->cboard.size * ZOOM;
	}
	render(*data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, \
			0, 0);
	data->block = 0;
	return (0);
}

void	init_init2(int argc, char *argv[], t_data *data)
{
	if (argc < 4)
	{
		ft_printf("For Julia set, please specify real and imaginary parts"
			" of the C as a second and third arguments.\n"
			"Examples:\n-0.4\t0.6\n0.285\t0.01\n-0.7017\t-0.3842\n"
			"-0.835\t-0.2321\n0.3\t0.5\n-0.7269\t0.1889\n-0.8\t0.156\n");
		exit(1);
	}
	data->fract_type = JULIA;
	data->julia.c_r = ft_atof(argv[2]);
	data->julia.c_i = ft_atof(argv[3]);
}

void	init_init(int argc, char *argv[], t_data *data)
{
	if (argc < 2)
	{
		ft_printf("Please specify type of the fractal as first argument."
			"The supported fractals are:\n\tmandelbrot\n\t"
			"julia\n\tburning_ship\n"
			"For julia fractal also specify real and imaginary parts of the C "
			"as a second and third arguments.\n");
		exit (1);
	}
	if (!ft_strcmp(argv[1], "mandelbrot"))
		data->fract_type = MANDELBROT;
	else if (!ft_strcmp(argv[1], "julia"))
		init_init2(argc, argv, data);
	else if (!ft_strcmp(argv[1], "burning_ship"))
		data->fract_type = BURN_SHIP;
	else
	{
		ft_printf("%s is not supported. Please specify correct type of fractal."
			"\nCorrect options are:\n\tmandelbrot\n\tjulia\n\tburning_ship\n", \
			argv[1]);
		exit (1);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	init_init(argc, argv, &data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WDT, WIN_HGT, "FRACTOL");
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIN_WDT, WIN_HGT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &(data.img.bpp), \
			&(data.img.line_len), &(data.img.endian));
	data.cboard.r = -2.5;
	data.cboard.i = 2.0;
	data.cboard.size = 4;
	data.block = 0;
	data.col_schm = 0;
	render(data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
	mlx_hook(data.win_ptr, 4, 0, &zoom, &data);
	mlx_hook(data.win_ptr, 2, 0, &kb_keys, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, &cancel, &data);
	mlx_loop(data.mlx_ptr);
}
