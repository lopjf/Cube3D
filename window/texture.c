#include "../cube.h"

char *get_color_tex(char wall_side, int x, int y)
{
	// unsigned int *img_data;
	// unsigned int color;
	// int bpp;
	// int line_length;
	// int endian;
	// x = 0;
	// y = 0;
	(void)x;
	(void)y;
	(void)wall_side;

	// img_data = (unsigned int *)mlx_get_data_addr(getb()->libx.no, &bpp, &line_length, &endian);
	// printf("img_data: %d\n", *img_data);
	// color = img_data[y * line_length / 4 + x];
	// printf("color: %d\n", color);
	// printf("bpp: %d\n", bpp);
	// printf("line_length: %d\n", line_length);
	// printf("endian: %d\n", endian);

	return ("255,255,255");
}