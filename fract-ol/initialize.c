#include "fractol.h"

//* Intialize the dataset
t_data initalzie(void)
{
    t_data create;

    create.mlx = NULL;
    create.window = NULL;
    create.min_r = 0;
    create.max_r = 0;
    create.min_i = 0;
    create.max_i = 0;
    create.center_i= 0;
    create.center_r = 0;
    create.shiftx_julia = 0;
    create.shifty_julia = 0;
    create.args = 0;
    create.color_shift = 1;
    create.resolution_shift = 0;
    create.count = 0;
    create.set = 0;
    create.image_data = x_calloc(sizeof(t_image));
    create.color = x_calloc(sizeof(t_color));
    return (create);
}

//* Setting up the mlx window 
void mlx_setup(t_data *create)
{
    create->mlx = mlx_init();
    if(create->mlx == NULL)
    {
        printf("Error creation");
        clean_everything(create);
        return ;
    }
    window_generate(create);
    create->image_data->image = mlx_new_image(create->mlx, WIDTH, HEIGHT);
    if(!create->image_data->image)
    {
        clean_everything(create);
        printf("ERROR\n");
        return ;
    }
    create->image_data->address = mlx_get_data_addr(create->image_data->image, &create->image_data->bits_per_pixel, &create->image_data->line_len, &create->image_data->endian);
    return ;
}

void window_generate(t_data *create)
{
    if(create->set == MALDERBOT)
    {
        create->window = mlx_new_window(create->mlx, WIDTH, HEIGHT, "Mandelbrot");
        if(create->window == NULL)
        {
            clean_everything(create);
            printf("Error in the creation\n");
            exit(-1);
        }
    }

    return ;
    // ! Need to setup for JULIA SET AS WELL
}
void	set_minmax(t_data *create)
{
	create->min_r = -2;
	create->max_r = create->min_r * -1 * WIDTH / HEIGHT;
	create->min_i = -2;
	create->max_i = create->min_i * -1 * HEIGHT / WIDTH;
	return ;
}

void	command_list(t_data *f)
{
	printf("Available commands:\n");
	printf("WASD: move screen\n");
	printf("Mouse Wheel: Zoom in / Zoom out\n");
	printf("ESC: quits program\n");
	printf("Left Shift: color shift\n");
	printf("Left Alt: cycle through resolution (max iteration)\n");
	printf("<!> +iterations = +resolution = -rendering speed <!>\n\n");
	// if (f->set == JULIA)
	// {
	// 	ft_printf("For Julia sets:\nDefault parameters = %d, %d (image \
	// 			center)\n", HEIGHT / 2, LENGTH / 2);
	// 	ft_printf("Right Click: change parameter to the current mouse x, y\n\n");
	// }
	return ;
}
