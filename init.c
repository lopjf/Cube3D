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
            j++;
        i++;
    }
    getb()->map_depth = j;
}

void init_all()
{
    // getb();
    // getb()->map_string = "\0";
    // getb()->map_depth = 0;
    // getb()->data.NO = "\0";
    // getb()->data.SO = "\0";
    // getb()->data.WE = "\0";
    // getb()->data.EA = "\0";
    // getb()->data.F = "\0";
    // getb()->data.C = "\0";
    

    getb();
    getb()->map_string = ft_strdup("\0");
    getb()->map = malloc(sizeof(char *) * 1);
    getb()->map[0] = NULL;
    getb()->map_depth = 0;
    getb()->data.NO = ft_strdup("\0");
    getb()->data.SO = ft_strdup("\0");
    getb()->data.WE = ft_strdup("\0");
    getb()->data.EA = ft_strdup("\0");
    getb()->data.F = ft_strdup("\0");
    getb()->data.C = ft_strdup("\0");
}