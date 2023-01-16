/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:19:14 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/11 12:53:46 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	create_window(t_data *pt)
{
	pt->ptr = mlx_init();
	pt->window = mlx_new_window(pt->ptr, WIN_SIZE, WIN_SIZE, "FRACTOL");
}

void	hook(t_data *pt)
{
	mlx_key_hook(pt->window, move_arrow, pt);
	mlx_hook(pt->window, 15, 0, exit_everything, pt);
	mlx_mouse_hook(pt->window, zoom, pt);
}

void	generate_image(t_data *pt)
{
	pt->image = mlx_new_image(pt->ptr, WIN_SIZE, WIN_SIZE);
	pt->address = mlx_get_data_addr(pt->image, &pt->bts_per_pixel,
			&pt->line_length, &pt->endian);
}

void	fractals_options(char *argv, t_data *pt)
{
	if (!ft_strcmp(argv, "julia") || !ft_strcmp(argv, "julia_1")
		|| !ft_strcmp(argv, "julia_2"))
	{
		create_julia(argv, pt);
		pt->fractals = ft_strdup(argv);
	}
	else if (!ft_strcmp(argv, "mandelbrot_set"))
	{
		create_mandelbrot(pt);
		pt->fractals = ft_strdup("mandelbrot_set");
	}
	else if (!ft_strcmp(argv, "mandelbrot_set"))
	{
		create_mandelbrot(pt);
		pt->fractals = ft_strdup("mandelbrot_set");
	}
	else if (!ft_strcmp(argv, "burning_ship"))
	{
		gen_burning_ship(pt);
		pt->fractals = ft_strdup("burning_ship");
	}
	mlx_put_image_to_window(pt->ptr, pt->window, pt->image, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	*pt;

	pt = malloc(sizeof(t_data));
	pt->zoom = 4.0;
	create_window(pt);
	generate_image(pt);
	if (argc != 2 || check_for_fractals(argv))
		generate_error();
	mlx_hook(pt->window, 17, 0, close_window, pt);
	fractals_options(argv[1], pt);
	hook(pt);
	mlx_loop(pt->ptr);
	free(pt);
	return (0);
}
