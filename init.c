#include "cube.h"

void init(t_base *base)
{
    get_base()->img.NO = "\0";
    base->img.SO = "\0";
    base->img.WE = "\0";
    base->img.EA = "\0";
    base->img.F = "\0";
    base->img.C = "\0";
}

t_base *get_base(void)
{
    static t_base base;

    return (&base);
}