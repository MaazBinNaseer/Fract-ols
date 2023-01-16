/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:23:07 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/16 16:46:53 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	work_through_julia(char *argv, t_data *pt)
{
	if (!ft_strcmp(argv, "julia_1"))
	{
		pt->center_re = -0.25;
		pt->center_img = -0.888;
	}
	else if (!ft_strcmp(argv, "julia_2"))
	{
		pt->center_re = -0.3842;
		pt->center_img = -0.70176;
	}
	else
	{
		pt->center_re = 0.01;
		pt->center_img = 0.285;
	}
	while (pt->n < 100 && pt->real * pt->real + pt->imaginery
		* pt->imaginery < 4)
	{
		pt->temp = pt->real * pt->real - pt->imaginery * pt->imaginery;
		pt->imaginery = 2 * pt->real * pt->imaginery + pt->center_re;
		pt->real = pt->temp + pt->center_img;
		pt->n++;
	}
	return (pt->n);
}

void	create_julia(char *argv, t_data *pt)
{
	pt->i = 0;
	while (pt->i < WIN_SIZE)
	{
		pt->j = 0;
		while (pt->j < WIN_SIZE)
		{
			pt->n = 0;
			pt->real = (pt->i - WIN_SIZE / 2) * (pt->zoom / WIN_SIZE) + pt->x;
			pt->imaginery = (pt->j - WIN_SIZE / 2) * (pt->zoom / WIN_SIZE)
				+ pt->y;
			if (pt->n < 100)
				put_pixel(pt, pt->i, pt->j, work_through_julia(argv, pt)
					* 0xCCCCFF);
			pt->j++;
		}
		pt->i++;
	}
}
