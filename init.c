#include "cube.h"

t_base *getb(void)
{
    static t_base base;

    return (&base);
}

void init_map_depth()
{
    int i;
    int j;

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

void init_data()
{
    getb()->map = malloc(sizeof(char *) * 1);
    getb()->map[0] = NULL;
    getb()->map_string = ft_strdup("\0");
    getb()->map_depth = 0;
    getb()->data.NOpath = ft_strdup("\0");
    getb()->data.SOpath = ft_strdup("\0");
    getb()->data.WEpath = ft_strdup("\0");
    getb()->data.EApath = ft_strdup("\0");
    getb()->data.Fpath = ft_strdup("\0");
    getb()->data.Cpath = ft_strdup("\0");
}

void init_libx()
{
    getb()->libx.mlx = mlx_init();
    getb()->libx.win = mlx_new_window(getb()->libx.mlx, 640, 480, "Cube 3d");
    getb()->libx.NO = mlx_xpm_file_to_image(getb()->libx.mlx, getb()->data.NOpath, &getb()->libx.img_width, &getb()->libx.img_height);
    if (getb()->libx.NO == NULL)
        free_and_exit("Error: Invalid NO path.");
    getb()->libx.SO = mlx_xpm_file_to_image(getb()->libx.mlx, getb()->data.SOpath, &getb()->libx.img_width, &getb()->libx.img_height);
    if (getb()->libx.SO == NULL)
        free_and_exit("Error: Invalid SO path.");
    getb()->libx.WE = mlx_xpm_file_to_image(getb()->libx.mlx, getb()->data.WEpath, &getb()->libx.img_width, &getb()->libx.img_height);
    if (getb()->libx.WE == NULL)
        free_and_exit("Error: Invalid WE path.");
    getb()->libx.EA = mlx_xpm_file_to_image(getb()->libx.mlx, getb()->data.EApath, &getb()->libx.img_width, &getb()->libx.img_height);
    if (getb()->libx.EA == NULL)
        free_and_exit("Error: Invalid EA path.");
}

void init_all()
{
    getb();
    init_data();
}