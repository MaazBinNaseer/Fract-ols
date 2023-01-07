#include "fractol.h"

int main(int ac, char **argv)
{
	t_data create;

	if (ac < 2 || !argv[1])
	{
		printf("error: missing argument.\n");
		return (-1);
	}
	create = initalzie();
	set_minmax(&create);
	create.args = argv;
	choose_fractal(&create, argv[1]);
	mlx_setup(&create);
	command_list(&create);
	mlx_loop_hook(create.mlx, &fractals_generate, &create);
	mlx_loop(create.mlx);
	return ;	
}
