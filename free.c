#include "cube.h"

void free_all()
{
    free(getb()->map);
    free(getb()->img.NO);
    free(getb()->img.SO);
    free(getb()->img.WE);
    free(getb()->img.EA);
    free(getb()->img.F);
    free(getb()->img.C);
}