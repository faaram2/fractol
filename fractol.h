/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeganya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:30:12 by ayeganya          #+#    #+#             */
/*   Updated: 2024/06/06 14:50:07 by ayeganya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"

# define WIN_WDT 1000
# define WIN_HGT 1000
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define CH_DPTH 100
# define ZOOM 2
# define SHIFT 100
# define MANDELBROT 1
# define JULIA 2
# define BURN_SHIP 3

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_cboard
{
	long double	r;
	long double	i;
	long double	size;
}	t_cboard;

typedef struct s_julia
{
	long double	c_r;
	long double	c_i;
}	t_julia;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			fract_type;
	int			block;
	int			col_schm;
	t_img		img;
	t_cboard	cboard;
	t_julia		julia;
}	t_data;

#endif
