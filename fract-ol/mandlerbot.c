#include "fractol.h"
/** 
* @brief Checks the mandlerbot is set in within the boundaries of the equation
* @example if the function has a set greater than the threshold it will
           the error. Otherwise, keep the iteration going. 
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

    while(i <= MAXIMUM_ITERATIONS + data->resolution_shift)
    {
        
    }




}