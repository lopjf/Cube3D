#include "cube.h"

void init()
{
    getb()->img.NO = "\0";
    getb()->img.SO = "\0";
    getb()->img.WE = "\0";
    getb()->img.EA = "\0";
    getb()->img.F = "\0";
    getb()->img.C = "\0";
}

t_base *getb(void)
{
    static t_base base;

    return (&base);
}