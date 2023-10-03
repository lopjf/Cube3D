#include "cube.h"

// int check_numbers(char *str, int i)
// {
//     int flag;

//     flag = 0;
//     if (str[i] >= '0' && str[i] <= '2')
//         i++;
//     else
//         free_and_exit("Error: Invalid RGB format.");
//     if (str[i] == ',')
//         return (i);
//     else if (str[i] >= '0' && str[i] <= '5')
//         i++;
//     else
//         free_and_exit("Error: Invalid RGB format.");
//     if (str[i] == ',')
//         return (i);
//     else if (str[i] >= '0' && str[i] <= '5')
//         i++;
//     else
//         free_and_exit("Error: Invalid RGB format.");
//     return (i);
// }


// static int check_numbers(char *str, int i)
// {
//     if (str[i] >= '0' && str[i] <= '2')
//         i++;
//     else
//         free_and_exit("Error: Invalid RGB format1.");

//     // printf("str[i]: %c\n", str[i]);
//     if (str[i] == ',' || str[i] == '\0')
//         return (i);
//     else if ((str[i - 1] == '0' || str[i - 1] == '1') && (str[i] >= '0' && str[i] <= '9'))
//         i++;
//     else if (str[i - 1] == '2' && (str[i] >= '0' && str[i] <= '5'))
//         i++;
//     else
//         free_and_exit("Error: Invalid RGB format2.");

//     if (str[i] == ',' || str[i] == '\0')
//         return (i);
//     else if ((str[i - 2] == '0' || str[i - 2] == '1') && (str[i] >= '0' && str[i] <= '9'))
//         i++;
//     else if (str[i - 2] == '2' && (str[i] >= '0' && str[i] <= '5'))
//         i++;
//     else
//         free_and_exit("Error: Invalid RGB format3.");

//     return (i);
// }

static int check_numbers(char *str, int i)
{
    int ret;
    int j;
    int nb;

    ret = 0;
    j = i;
    while (str[j] >= '0' && str[j] <= '9')
    {
        j++;
        ret++;
    }
    // printf("ret: %d\n", ret);
    nb = ft_atoi(str + i);
    // printf("nb: %d\n", nb);
    if (nb >= 0 && nb <= 255)
        return (ret);
    else
        free_and_exit("Error: Invalid RGB format.");
    return (ret);
}

static void check_format(char *str)
{
    int i;

    i = 0;
    i = check_numbers(str, i);
    // printf("i: %d\n", i);
    if (str[i] == ',')
        i++;
    else
        free_and_exit("Error: Invalid RGB format.");
    i += check_numbers(str, i);
    // printf("i: %d\n", i);
    if (str[i] == ',')
        i++;
    else
        free_and_exit("Error: Invalid RGB format.");
    i += check_numbers(str, i);
    // printf("i: %d\n", i);
    if (str[i] == '\0')
        return ;
    else
        free_and_exit("Error: Invalid RGB format.");
}

void check_rgb()
{
    // printf("\nFpath:\n%s\n", getb()->data.Fpath);
    // printf("\nCpath:\n%s\n", getb()->data.Cpath);
    check_format(getb()->data.Fpath);
    check_format(getb()->data.Cpath);
}