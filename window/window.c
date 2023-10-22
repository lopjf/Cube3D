#include "cube.h"

void	display_win(void)
{
	mlx_put_image_to_window(getb()->libx.mlx, \
	getb()->libx.win, getb()->libx.no, 64, 64);
}

int	close_win(void)
{
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.no);
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.so);
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.we);
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.ea);
	mlx_destroy_window(getb()->libx.mlx, getb()->libx.win);
	mlx_destroy_display(getb()->libx.mlx);
	free(getb()->libx.mlx);
	free_data();
	exit(0);
}

int	fetch_key(int keycode)
{
	if (keycode == KEY_ESC)
		close_win();
	else if (keycode == KEY_RA || keycode == KEY_LA)
		printf("Moving vision\n");
	else if (keycode == KEY_W || keycode == KEY_D || \
	keycode == KEY_S || keycode == KEY_A)
		printf("Moving POV\n");
	return (0);
}
