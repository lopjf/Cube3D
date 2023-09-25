#include "cube.h"

static void check_wrong_char()
{
    int i;
    int j;
    char c;

    i = 0;
    while (getb()->map[i] != NULL)
    {
        j = 0;
        while (getb()->map[i][j] != '\0')
        {
            c = getb()->map[i][j];
            if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != ' '&& c != '\n')
                exit (printf("Error: Invalid character in map\n"));
            j++;
        }
        i++;
    }
}

void check_map()
{
    check_wrong_char();
}