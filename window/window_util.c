#include "../cube.h"

int get_rgb(char *rgb)
{
	int r;
	int g;
	int b;
	int i;

	i = 0;
	r = ft_atoi(rgb + i);
	while (rgb[i] != ',' && rgb[i] != '\0')
		i++;
	i++;
	g = ft_atoi(rgb + i);
	while (rgb[i] != ',' && rgb[i] != '\0')
		i++;
	i++;
	b = ft_atoi(rgb + i);
	return (0 << 24 | r << 16 | g << 8 | b);
}