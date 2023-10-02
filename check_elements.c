#include "cube.h"

// static int count_nb(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i] != '\0' && str[i] != ',')
//     {
//         if (str[i] >= '0' || str[i] <= '9')
//             i++;
//     }
//     return (i);
// }

void check_elements()
{
    int i;

    i = 0;
    while (getb()->data.Fpath[i] != '\0')
    {
        // count_nb(getb()->data.Fpath[i]);
        i++;
    }
}