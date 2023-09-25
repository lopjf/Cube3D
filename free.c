#include "cube.h"

void free_all()
{
    int i;

    i = 0;
    while (getb()->map[i] != NULL)
    {
        free(getb()->map[i]);
        i++;
    }
    if (getb()->map != NULL)
        free(getb()->map);
    if (getb()->data.NO != NULL)
        free(getb()->data.NO);
    if (getb()->data.SO != NULL)
        free(getb()->data.SO);
    if (getb()->data.WE != NULL)
        free(getb()->data.WE);
    if (getb()->data.EA != NULL)
        free(getb()->data.EA);
    if (getb()->data.F != NULL)
        free(getb()->data.F);
    if (getb()->data.C != NULL)
        free(getb()->data.C);
}