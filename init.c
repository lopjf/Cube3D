#include "cube.h"

t_base *getb(void)
{
    static t_base base;

    return (&base);
}

void init_all()
{
    getb();
    getb()->map = (char **)malloc(sizeof(char *) * 40);
    getb()->map[0] = "\0";
    getb()->map_depth = 39;
    getb()->data.NO = "\0";
    getb()->data.SO = "\0";
    getb()->data.WE = "\0";
    getb()->data.EA = "\0";
    getb()->data.F = "\0";
    getb()->data.C = "\0";
}