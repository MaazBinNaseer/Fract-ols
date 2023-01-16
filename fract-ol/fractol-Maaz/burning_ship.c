/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:44:19 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/16 14:01:01 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	work_through_ship(t_data *pt)
{
	pt->center_re = (pt->i - WIN_SIZE / 2.0) * pt->zoom / WIN_SIZE + pt->x;
	pt->center_img = (pt->j - WIN_SIZE / 2.0) * pt->zoom / WIN_SIZE + pt->y;
	while (pt->n < 100 && pt->real * pt->real + pt->imaginery
		* pt->imaginery < 4)
	{
		pt->temp = pt->real * pt->real - pt->imaginery * pt->imaginery
			+ pt->center_re;
		pt->imaginery = fabs(2 * pt->real * pt->imaginery) + pt->center_img;
		pt->real = pt->temp;
		pt->n++;
	}
	return (pt->n);
}

void	gen_burning_ship(t_data *pt)
{
	pt->i = 0;
	while (pt->i < WIN_SIZE)
	{
		pt->j = 0;
		while (pt->j < WIN_SIZE)
		{
			pt->n = 0;
			pt->real = 0;
			pt->imaginery = 0;
			if (pt->n < 100)
				put_pixel(pt, pt->i, pt->j, work_through_ship(pt) * 0xE0B0FF);
			pt->j++;
		}
		pt->i++;
	}
}
