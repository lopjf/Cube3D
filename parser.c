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

static int map_bool(char *buf)
{
  if (ft_strncmp(getb()->data.NO, "\0", 1) != 0 && ft_strncmp(getb()->data.SO, "\0", 1) != 0 && ft_strncmp(getb()->data.WE, "\0", 1) != 0 && ft_strncmp(getb()->data.EA, "\0", 1) != 0 && ft_strncmp(getb()->data.F, "\0", 1) != 0 && ft_strncmp(getb()->data.C, "\0", 1) != 0)
    if (buf[0] == ' ' || buf[0] == '1')
      return 0;
  return 1;
}

static void get_elements(char *buf)
{
  int i;

  i = skip_spaces(buf, 0);
  if (ft_strncmp((buf + i), "NO ", 3) == 0) // || ft_strncmp((buf + i), "NO\0", 3)
    insert(&getb()->data.NO, buf, i, 2);
  else if (ft_strncmp((buf + i), "SO ", 3) == 0)
    insert(&getb()->data.SO, buf, i, 2);
  else if (ft_strncmp((buf + i), "WE ", 3) == 0)
    insert(&getb()->data.WE, buf, i, 2);
  else if (ft_strncmp((buf + i), "EA ", 3) == 0)
    insert(&getb()->data.EA, buf, i, 2);
  else if (ft_strncmp((buf + i), "F ", 2) == 0)
    insert(&getb()->data.F, buf, i, 1);
  else if (ft_strncmp((buf + i), "C ", 2) == 0)
    insert(&getb()->data.C, buf, i, 1);
  else if (ft_strncmp((buf + i), "\n\0", 2) == 0)
  {
  }
  else
    exit (printf("Error: Invalid element\n"));
}

void parse(char *map_name)
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
      if (map_bool(buf) != 0)
        get_elements(buf);
      else
        getb()->map = get_whole_map(buf, fd);
      free(buf);
    }
    close(fd);
}