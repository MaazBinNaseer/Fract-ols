#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int generate_color(t_data *create)
{
    int color_value;

    color_value = create->count * 15;
    create->color->r = get_color_red(color_value);
    create->color->g = get_color_green(color_value);
    create->color->b = get_color_blue(color_value);
    apply_color_shift(create);
    return (create_trgb(0, create->color->r, create->color->g, create->color->b));
} 

int fractals_generate(t_data *create)
{
    if(create->set == MALDERBOT)
        create_mandlbrot(create);
    return (0);
}

void choose_fractal(t_data *create, char *arg)
{
    arg = ft_str_tolower(arg);
    if (ft_strcmp(arg, "mandelbrot") == 0)
		create->set = MALDERBOT;
	// else if (ft_strcmp(arg, "julia") == 0)
	// 	create->set = JULIA;
	else
	{
		printf("Error: no such fractal\n");
		printf("Available fractals: Mandelbrot\n");
		clean_everything(create);
	}
	return ;

}
