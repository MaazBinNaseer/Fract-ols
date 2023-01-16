/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:44:57 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/10 15:28:51 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	check_for_fractals(char **argv)
{
	if (!ft_strcmp(argv[1], "julia") || !ft_strcmp(argv[1], "julia_1")
		|| !ft_strcmp(argv[1], "julia_2") || !ft_strcmp(argv[1],
			"mandelbrot_set") || !ft_strcmp(argv[1], "burning_ship"))
		return (0);
	return (1);
}

void	generate_error(void)
{
	write(1, "Usage: ./fractol :Name of the fractal: \n", 41);
	write(1, "Available Fractals:\n", 21);
	write(1, " -----------mandelbrot_set---------\n", 37);
	write(1, "*********julia***********\n", 27);
	write(1, "\t 1. julia\n\t 2. julia_1\n\t 3. julia_2\n", 38);
	write(1, "---> burning_ship\n", 19);
	exit(EXIT_FAILURE);
}

int	exit_everything(void)
{
	exit(EXIT_FAILURE);
	return (0);
}
