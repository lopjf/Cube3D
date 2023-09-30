#include "cube.h"

void free_and_exit(char *str)
{
    free_all();
    exit (printf("%s\n", str));
}

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
    
    if (getb()->map_string != NULL)
        free(getb()->map_string);
    if (getb()->data.NOpath != NULL)
        free(getb()->data.NOpath);
    if (getb()->data.SOpath != NULL)
        free(getb()->data.SOpath);
    if (getb()->data.WEpath != NULL)
        free(getb()->data.WEpath);
    if (getb()->data.EApath != NULL)
        free(getb()->data.EApath);
    if (getb()->data.Fpath != NULL)
        free(getb()->data.Fpath);
    if (getb()->data.Cpath != NULL)
        free(getb()->data.Cpath);
    
}