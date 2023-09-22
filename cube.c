#include "cube.h"

int	main(int ac, char *av[])
{
	check_arg(ac, av);
	init_all();
	parse(av[1]);

	printf("\nNO:\n%s\n", getb()->img.NO);
	printf("\nSO:\n%s\n", getb()->img.SO);
	printf("\nWE:\n%s\n", getb()->img.WE);
	printf("\nEA:\n%s\n", getb()->img.EA);
	printf("\nF:\n%s\n", getb()->img.F);
	printf("\nC:\n%s\n", getb()->img.C);
	printf("\nmap:\n%s\n", getb()->map);

	free_all();
	return (0);
}
