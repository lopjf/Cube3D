#include "cube.h"

int	main(int ac, char *av[])
{
	check_arg(ac, av);
	init_all();
	parse(av[1]);

	printf("\nNO:\n%s\n", getb()->data.NO);
	printf("\nSO:\n%s\n", getb()->data.SO);
	printf("\nWE:\n%s\n", getb()->data.WE);
	printf("\nEA:\n%s\n", getb()->data.EA);
	printf("\nF:\n%s\n", getb()->data.F);
	printf("\nC:\n%s\n", getb()->data.C);
	printf("\nmap:\n%s\n", getb()->map);

	free_all();
	return (0);
}
