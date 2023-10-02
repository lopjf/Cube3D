#include "cube.h"

void	display_win()
{
	mlx_put_image_to_window(getb()->libx.mlx, getb()->libx.win, getb()->libx.NO, 64, 64);
}

int	close_win()
{
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.NO);
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.SO);
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.WE);
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.EA);
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
	if (keycode == KEY_W || keycode == KEY_D || \
	keycode == KEY_S || keycode == KEY_A || keycode == KEY_RA || keycode == KEY_LA)
	{
        printf("key pressed\n");
	}
    return (0);
}