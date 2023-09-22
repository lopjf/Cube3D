#include "cube.h"

int	main(int ac, char *av[])
{
	check_arg(ac, av);
	getb();
	init();
	// peut etre utiliser GNL pour traiter chaque ligne une a une.
	// dispatch les elements dans leur variable de la struct. NO SO WE EA F C and map
	parse(av[1]);
	// getb()->map = get_map(av[1]);
	// need to parse things utils the actual map
	printf("\nNO:\n%s\n", getb()->img.NO);
	printf("\nSO:\n%s\n", getb()->img.SO);
	printf("\nWE:\n%s\n", getb()->img.WE);
	printf("\nEA:\n%s\n", getb()->img.EA);
	printf("\nF:\n%s\n", getb()->img.F);
	printf("\nC:\n%s\n", getb()->img.C);
	printf("\nmap:\n%s\n", getb()->map);

	free_all();
	return 0;
}
