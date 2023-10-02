#include "cube.h"

static void print_map()
{
	printf("\nNOpath:\n%s\n", getb()->data.NOpath);
	printf("\nSOpath:\n%s\n", getb()->data.SOpath);
	printf("\nWEpath:\n%s\n", getb()->data.WEpath);
	printf("\nEApath:\n%s\n", getb()->data.EApath);
	printf("\nFpath:\n%s\n", getb()->data.Fpath);
	printf("\nCpath:\n%s\n", getb()->data.Cpath);

	printf("\nmap:\n%s\n", getb()->map_string);
	
	printf("\nmap:\n");
	int i = 0;
	while (getb()->map[i] != NULL)
	{
		printf("%s\n", getb()->map[i]);
		i++;
	}

	printf("\nmap_depth:\n%d\n", getb()->map_depth);
}

int	main(int ac, char *av[])
{
	check_arg(ac, av);
	init_all();
	parse(av[1]);

	print_map();

	check_map();

	init_libx();
	display_win();
	mlx_key_hook(getb()->libx.win, fetch_key, getb());
	mlx_hook (getb()->libx.win, 17, (1L << 2), close_win, getb());
	mlx_loop(getb()->libx.mlx);
	return (0);
}
