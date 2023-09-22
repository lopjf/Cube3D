#include "cube.h"

void free_all(t_base *base)
{
    free(base->map);
    free(base->img.NO);
    free(base->img.SO);
    free(base->img.WE);
    free(base->img.EA);
    free(base->img.F);
    free(base->img.C);
    free(base);
}