/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_utilis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:48:53 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/16 13:50:04 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	put_pixel(t_data *pt, int x, int y, int color)
{
	char	*destination;

	destination = pt->address + (y * pt->line_length + x * (pt->bts_per_pixel
				/ 8));
	*(unsigned int *)destination = color;
}

int	zoom(int keycode, int x, int y, t_data *pt)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_DOWN || keycode == MOUSE_UP)
	{
		if (keycode == MOUSE_DOWN)
			pt->zoom /= 0.8;
		else
			pt->zoom *= 0.8;
	}
	mlx_clear_window(pt->ptr, pt->window);
	if (!ft_strcmp(pt->fractals, "julia") || !ft_strcmp(pt->fractals, "julia_1")
		|| !ft_strcmp(pt->fractals, "julia_2"))
		create_julia(pt->fractals, pt);
	if (!ft_strcmp(pt->fractals, "mandelbrot_set"))
		create_mandelbrot(pt);
	if (!ft_strcmp(pt->fractals, "burning_ship"))
		gen_burning_ship(pt);
	mlx_put_image_to_window(pt->ptr, pt->window, pt->image, 0, 0);
	return (0);
}

int	move_arrow(int keycode, t_data *pt)
{
	if (keycode == ESC_KEY)
		close_window(pt);
	if (keycode == LEFT_KEY)
		pt->x += 0.1;
	if (keycode == RIGHT_KEY)
		pt->x -= 0.1;
	if (keycode == UP_KEY)
		pt->y += 0.1;
	if (keycode == DOWN_KEY)
		pt->y -= 0.1;
	mlx_clear_window(pt->ptr, pt->window);
	if (!ft_strcmp(pt->fractals, "julia") || !ft_strcmp(pt->fractals, "julia_1")
		|| !ft_strcmp(pt->fractals, "julia_2"))
		create_julia(pt->fractals, pt);
	if (!ft_strcmp(pt->fractals, "mandelbrot_set"))
		create_mandelbrot(pt);
	if (!ft_strcmp(pt->fractals, "burning_ship"))
		gen_burning_ship(pt);
	mlx_put_image_to_window(pt->ptr, pt->window, pt->image, pt->x, pt->y);
	return (0);
}

int	close_window(t_data *pt)
{
	write(1, "Closing Windows\n", 17);
	mlx_destroy_window(pt->ptr, pt->window);
	exit(1);
}
