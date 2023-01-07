#include "fractol.h"

int get_color_red(int color_value)
{
    if(color_value >= 0 && color_value <= 255)
        return (255);
    else if ( color_value > 255 && color_value <= 510)
        return (255 - (color_value - 255));
    else if ( color_value > 510 && color_value <= 1020)
        return (0);
    else
        return (255);
}

int get_color_green(int color_value)
{
    if(color_value >= 0 && color_value <= 255)
        return (color_value);
    if(color_value > 255 && color_value <= 765)
            return (255);
    else if ( color_value > 765 && color_value <= 1020)
        return (255 - (color_value - 765));
    else if ( color_value > 1020 && color_value <= 1075)
        return (0);
    else
        return (255);
}

int get_color_blue(color_value)
{
    if (color_value >= 0 && color_value <= 510)
        return (0);
    else if (color_value > 510 && color_value <= 765)
        return (color_value - 510);
    else
        return (255);
}

void color_shift(t_data *create)
{
    create->color_shift += 1;
    if(create->color_shift > 5)
        create->color_shift = 1;
    return ;
}

void apply_color_shift(t_data *create)
{
    if(create->color_shift == 1)
    {
        create->color->r += 120;
        create->color->b += 5;
    }
    else if (create->color_shift == 2)
    {
        create->color->r += 65;
        create->color->b += 50;
    }
    else if (create->color_shift == 3)
        create->color->g += 55;
    else if (create->color_shift == 4)
        create->color->b += 120;
    else
    {
        create->color->b = 75;
        create->color->g += 65;
    }
    return ;
}