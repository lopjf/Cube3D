#include "cube.h"

t_base	*getb(void)
{
	static t_base	base;

	return (&base);
}

void	init_map_depth(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (getb()->map_string[i] != '\0')
	{
		if (getb()->map_string[i] == '\n')
		{
			while (getb()->map_string[i] == '\n')
				i++;
			if (getb()->map_string[i] != '\0')
				break ;
			j++;
		}
		i++;
	}
	getb()->map_depth = j;
}

void	init_data(void)
{
	getb()->map = malloc(sizeof(char *) * 1);
	getb()->map[0] = NULL;
	getb()->map_string = ft_strdup("\0");
	getb()->map_depth = 0;
	getb()->data.no_path = ft_strdup("\0");
	getb()->data.so_path = ft_strdup("\0");
	getb()->data.we_path = ft_strdup("\0");
	getb()->data.ea_path = ft_strdup("\0");
	getb()->data.f_path = ft_strdup("\0");
	getb()->data.c_path = ft_strdup("\0");
	getb()->dda = get_dda();
}

void	init_libx(void)
{
	t_base	*b;

	b = getb();
	getb()->libx.mlx = mlx_init();
	b->libx.win = mlx_new_window(b->libx.mlx, WIN_W, WIN_H, "Cube 3d");
	b->libx.no = mlx_xpm_file_to_image(b->libx.mlx, b->data.no_path, \
&b->libx.img_width, &b->libx.img_height);
	if (getb()->libx.no == NULL)
		free_and_exit("Error: Invalid no path.");
	b->libx.so = mlx_xpm_file_to_image(b->libx.mlx, b->data.so_path, \
&b->libx.img_width, &b->libx.img_height);
	if (getb()->libx.so == NULL)
		free_and_exit("Error: Invalid so path.");
	b->libx.we = mlx_xpm_file_to_image(b->libx.mlx, b->data.we_path, \
&b->libx.img_width, &b->libx.img_height);
	if (getb()->libx.we == NULL)
		free_and_exit("Error: Invalid we path.");
	b->libx.ea = mlx_xpm_file_to_image(b->libx.mlx, b->data.ea_path, \
&b->libx.img_width, &b->libx.img_height);
	if (getb()->libx.ea == NULL)
		free_and_exit("Error: Invalid ea path.");
}

void	init_before(void)
{
	init_data();
}

void	init_after(void)
{
	init_dda();
	init_libx();
}

