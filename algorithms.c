/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeganya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:05:55 by ayeganya          #+#    #+#             */
/*   Updated: 2024/06/06 15:07:08 by ayeganya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(long double r, long double i)
{
	int			j;
	long double	r1;
	long double	i1;
	long double	r1_temp;

	j = 0;
	r1 = r;
	i1 = i;
	while (j < CH_DPTH)
	{
		r1_temp = r1 * r1 - i1 * i1 + r;
		i1 = 2 * r1 * i1 + i;
		r1 = r1_temp;
		if (r1 * r1 + i1 * i1 > 4)
			return (j);
		j++;
	}
	return (-1);
}

int	julia(t_data data, long double r, long double i)
{
	int			j;
	long double	r1;
	long double	i1;
	long double	r1_temp;

	j = 0;
	r1 = r;
	i1 = i;
	while (j < CH_DPTH)
	{
		r1_temp = r1 * r1 - i1 * i1 + data.julia.c_r;
		i1 = 2 * r1 * i1 + data.julia.c_i;
		r1 = r1_temp;
		if (r1 * r1 + i1 * i1 > 4)
			return (j);
		j++;
	}
	return (-1);
}

int	burning_ship(long double r, long double i)
{
	int			j;
	long double	r1;
	long double	i1;
	long double	r1_temp;

	j = 0;
	r1 = r;
	i1 = i;
	while (j < CH_DPTH)
	{
		r1_temp = i1 * i1 - r1 * r1 - r;
		i1 = fabsl(2 * r1 * i1) - i;
		r1 = fabsl(r1_temp);
		if (r1 * r1 + i1 * i1 > 4)
			return (j);
		j++;
	}
	return (-1);
}
