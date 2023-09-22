#include "cube.h"

static int skip_spaces(char *buf, int i)
{
  while (buf[i] == ' ')
    i++;
  return (i);
}

static void insert(char **str, char *buf, int i, int skip)
{
  if (ft_strncmp(*str, "\0", 1) == 0)
    *str = ft_strdup(buf + skip_spaces(buf, i + skip));
  else
    exit (printf("Error: An element is defined more than once.\n"));
}

// static int map_bool(t_base *base)
// {
  
// }

static void analize(t_base *base, char *buf)
{
  int i;

  // problem with this implementation:
  // NO
  // NO assets/textures/walls/stone_bricks/3.xpm
  // will still work.
  // solution:
  // add bools to the struct and set them to 1 when an element has been found once

  i = skip_spaces(buf, 0);
  if (ft_strncmp((buf + i), "NO ", 3) == 0)
    insert(&base->img.NO, buf, i, 2);
  else if (ft_strncmp((buf + i), "SO ", 3) == 0)
    insert(&base->img.SO, buf, i, 2);
  else if (ft_strncmp((buf + i), "WE ", 3) == 0)
    insert(&base->img.WE, buf, i, 2);
  else if (ft_strncmp((buf + i), "EA ", 3) == 0)
    insert(&base->img.EA, buf, i, 2);
  else if (ft_strncmp((buf + i), "F ", 2) == 0)
    insert(&base->img.F, buf, i, 1);
  else if (ft_strncmp((buf + i), "C ", 2) == 0)
    insert(&base->img.C, buf, i, 1);
  // else if (map_bool == 0)
  //   printf("map_bool = 0\n");
  // else if all the elements are not NULL
  // then get the map
}

void parse(char *map_name, t_base *base)
{
    int fd;
    char *buf;

    fd = open(map_name, O_RDONLY);
    if (fd == -1)
		  return ;

    while (buf != NULL)
    {
      buf = get_next_line(fd);
      if (buf == NULL)
        break;
      analize(base, buf);
      free(buf);
    }
    close(fd);
    base->map = ft_strdup("ok");
}