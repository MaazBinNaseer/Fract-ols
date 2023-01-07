//Libraries Reuired
#include <stdio.h>
#include <math.h>

/*---Images && Color Structs Data----*/
typedef struct s_image
{
    void    *image;
    char    *address;
    int     bits_per_pixel;
    int     line_len;
    int     endian;
} t_image;

typedef struct s_color
{
    int     r;
    int     g;
    int     b;
    int     t;   
}  t_color;

/*------- Master Data---- ----*/
typedef struct s_data
{
    void            *mlx;
    void            *window;
    t_image         *image_data;
    double          min_r;
    double          max_r;
    double          center_r;
    double          min_i;
    double          max_r;
    double          center_i;
    unsigned int    count;
    int             color_shift;
    int             resolution_shift;
    double          shiftx_julia;
    double          shifty_julia;
    char            **args;
    t_color         *color;
}   t_data;
