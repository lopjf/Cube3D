#include "cube.h"

// static void print_map()
// {
// 	printf("\nNOpath:\n%s\n", getb()->data.no_path);
// 	printf("\nSOpath:\n%s\n", getb()->data.so_path);
// 	printf("\nWEpath:\n%s\n", getb()->data.we_path);
// 	printf("\nEApath:\n%s\n", getb()->data.ea_path);
// 	printf("\nFpath:\n%s\n", getb()->data.f_path);
// 	printf("\nCpath:\n%s\n", getb()->data.c_path);

// 	printf("\nmap_string:\n%s\n", getb()->map_string);

// 	printf("\nmap:\n");
// 	int i = 0;
// 	while (getb()->map[i] != NULL)
// 	{
// 		printf("%s\n", getb()->map[i]);
// 		i++;
// 	}

// 	printf("\nmap_depth:\n%d\n", getb()->map_depth);
// }

int	main(int ac, char *av[])
{
	check_arg(ac, av);
	init_all();
	parse(av[1], getb(), 0, "\0");

	// print_map();

	check_rgb();
	check_map();

	init_libx();
	display_win();
	mlx_key_hook(getb()->libx.win, fetch_key, getb());
	mlx_hook (getb()->libx.win, 17, (1L << 2), close_win, getb());
	mlx_loop(getb()->libx.mlx);
	return (0);
}
