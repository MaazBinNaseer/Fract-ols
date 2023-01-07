#include "fractol.h"

void put_px(t_image *img, int x, int y , int color)
{
    char *pixel; 

    pixel = img->address + (y * img->line_len + x *(img->bits_per_pixel / 8));
    *(int *)pixel = color;
}

void clean_everything(t_data *create)
{
    if(create->image_data->image)
    {
        mlx_destroy_image(create->mlx, create->image_data->image);
        free(create->image_data);
    }
    if(create->window)
        mlx_destroy_window(create->mlx, create->window);
    if(create->color)
        free(create->color);
    write(1, "Goodbye from this trip\n", 23);
    exit(0);
}

