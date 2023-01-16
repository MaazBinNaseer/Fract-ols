/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:25:03 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/16 13:51:03 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "mlx/mlx.h"
# include <complex.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*ptr;
	void	*image;
	void	*window;
	float	x;
	float	y;
	float	real;
	float	imaginery;
	float	temp;
	float	zoom;
	float	center_re;
	float	center_img;
	char	*address;
	char	*fractals;
	int		i;
	int		j;
	int		n;
	int		endian;
	int		line_length;
	int		bts_per_pixel;
}			t_data;

# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define WIN_SIZE 1200
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126
# define ESC_KEY 53

//? ---------- FRACTALS UTILS --------------------
void		put_pixel(t_data *pt, int x, int y, int color);
int			move_arrow(int keycode, t_data *pt);
int			zoom(int keycode, int x, int y, t_data *pt);
int			exit_everything(void);
int			check_for_fractals(char **argv);
void		generate_error(void);
int			close_window(t_data *pt);

//! Fractals
void		create_julia(char *argv, t_data *pt);
void		create_mandelbrot(t_data *pt);
void		gen_burning_ship(t_data *pt);

//* LIBFT UTILITIES -----------------
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(const char *s1);
#endif
