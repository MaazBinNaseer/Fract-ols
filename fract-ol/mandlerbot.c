#include "fractol.h"

/** HOW IT WORKS--------------
 * * @brief -> Checks whether it fits the mandlerbot equation 
 * # @example -> Iterate through each pixel and return equation
 * # If the value of eq is greater than 2 or threshold return error 
 * * Furthermore, zi = y, zr = x in this case. 
*/

int mandlerbot_eq(double cr, double ci, t_data *data)
{
    double  zi;
    double  zr;
    double  temp;
    int     i;

    zi = 0;
    zr = 0;
    i = 0;

    while(i <= MAXIMUM_ITERATION + data->resolution_shift)
    {
        if(zi * zi + zr * zr > 2.0 )
        {
            data->count = 0;
            return (0); 
        }
        temp = 2 * zi * zr + ci;
        zr = zr * zr - zi * zi + cr;
        zi = temp;
        i++;
    }
    data->count = i;
    return (1);
}

void create_mandlbrot(t_data *create)
{
    int     x;
    int     y;
    double  pr;
    double  pi;

    y = -1;
    while(++y < HEIGHT)
    {
        pi = create->max_i + ((double)y * (create->min_i - create->max_i) / HEIGHT);
        x= -1;
        while(++x < WIDTH)
        {
            pr = create->min_r + ((double)x * (create->max_r - create->min_r) / WIDTH);
            if(mandlerbot_eq(pr, pi, create) == 0)
                    put_px(create->image_data, x, y,generate_color(create));
            else
                put_px(create->image_data, x, y, create_trgb(0,0,0,0));
        } 
    }
    mlx_put_image_to_window(create->mlx, create->window, create->image_data, 0, 0);
    return ;
}