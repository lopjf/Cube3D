#include "cube.h"

int	main(int ac, char *av[])
{
	check_arg(ac, av);
	init_data();
	parse(av[1], getb(), 0, "\0");
	check_rgb();
	check_map();
	init_dda();
	init_libx();
	display_win();
	mlx_key_hook(getb()->libx.win, fetch_key, getb());
	mlx_hook (getb()->libx.win, 17, (1L << 2), close_win, getb());
	mlx_loop(getb()->libx.mlx);
	return (0);
}
