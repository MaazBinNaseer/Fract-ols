#ifndef FRACTOL_H
#define FRACTOL_H


#define MAXIMUM_ITERATION 25
#define MALDERBOT 1
#define HEIGHT 1100 
#define WIDTH 1100

//Libraries Reuired
#include <stdio.h>
#include <math.h>
#include "mlx/mlx.h"

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
    double          max_i;
    double          center_i;
    unsigned int    count;
    int             color_shift;
    int             resolution_shift;
    int             set;
    double          shiftx_julia;
    double          shifty_julia;
    char            **args;
    t_color         *color;
}   t_data;


// ? -------MALDERBROT----------
void create_mandlbrot(t_data *create);

//! ----------Intialize------------ 
t_data initalzie(void);
void mlx_setup(t_data *create);
void	set_minmax(t_data *create);
void	command_list(t_data *f);


// #-------Colors---------------- 
int get_color_red(int color_value);
int get_color_green(int color_value);
int get_color_blue(color_value);
void apply_color_shift(t_data *create);


//* ----RENDERING ------------------
int generate_color(t_data *create);
int	create_trgb(int t, int r, int g, int b);
int fractals_generate(t_data *create);
void choose_fractal(t_data *create, char *arg);

// ------------UTILS FUNCTIONS----------------
void    put_px(t_image *img, int x, int y , int color);
void	*x_calloc(size_t size);
char	*ft_str_tolower(char *str);
int     ft_strcmp(const char *s1, const char *s2);
void    clean_everything(t_data *create);
#endif