#include "cube.h"

void	free_and_exit(char *str)
{
	free_data();
	exit(printf("%s\n", str));
}

void	free_data(void)
{
	int	i;

	i = 0;
	while (getb()->map[i] != NULL)
	{
		free(getb()->map[i]);
		i++;
	}
	if (getb()->map != NULL)
		free(getb()->map);
	if (getb()->map_string != NULL)
		free(getb()->map_string);
	if (getb()->data.no_path != NULL)
		free(getb()->data.no_path);
	if (getb()->data.so_path != NULL)
		free(getb()->data.so_path);
	if (getb()->data.we_path != NULL)
		free(getb()->data.we_path);
	if (getb()->data.ea_path != NULL)
		free(getb()->data.ea_path);
	if (getb()->data.f_path != NULL)
		free(getb()->data.f_path);
	if (getb()->data.c_path != NULL)
		free(getb()->data.c_path);
}
