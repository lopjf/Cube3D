#include "cube.h"

void	display_win()
{
	write(1, "display_win\n", 12);
	mlx_put_image_to_window(getb()->libx.mlx, getb()->libx.win, getb()->libx.NO, 64, 64);
	write(1, "HHERRREEE\n", 10);
}

int	close_win()
{
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.NO);
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.SO);
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.WE);
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.EA);
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.F);
	mlx_destroy_image(getb()->libx.mlx, getb()->libx.C);
	mlx_destroy_window(getb()->libx.mlx, getb()->libx.win);
	mlx_destroy_display(getb()->libx.mlx);
    return (0);
}

int	fetch_key(int keycode)
{
	if (keycode == KEY_ESC)
		close_win();
	if (keycode == KEY_W || keycode == KEY_D || \
	keycode == KEY_S || keycode == KEY_A)
	{
		// if (move(keycode, base) == 1)
			// display_game(base, 0, 0, 0);
        printf("key pressed\n");
	}
    return (0);
}