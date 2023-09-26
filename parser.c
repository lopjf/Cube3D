#include "cube.h"


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

  // the || matters here to get a more precise error message when NO is input/ maybe not important
  i = skip_spaces(buf, 0);
  if (ft_strncmp((buf + i), "NO ", 3) == 0 || ft_strncmp((buf + i), "NO\n", 3) == 0)
    insert(&getb()->data.NO, buf, i, 2);
  else if (ft_strncmp((buf + i), "SO ", 3) == 0 || ft_strncmp((buf + i), "SO\n", 3) == 0)
    insert(&getb()->data.SO, buf, i, 2);
  else if (ft_strncmp((buf + i), "WE ", 3) == 0 || ft_strncmp((buf + i), "WE\n", 3) == 0)
    insert(&getb()->data.WE, buf, i, 2);
  else if (ft_strncmp((buf + i), "EA ", 3) == 0 || ft_strncmp((buf + i), "EA\n", 3) == 0)
    insert(&getb()->data.EA, buf, i, 2);
  else if (ft_strncmp((buf + i), "F ", 2) == 0 || ft_strncmp((buf + i), "F\n", 3) == 0)
    insert(&getb()->data.F, buf, i, 1);
  else if (ft_strncmp((buf + i), "C ", 2) == 0 || ft_strncmp((buf + i), "C\n", 3) == 0)
    insert(&getb()->data.C, buf, i, 1);
  else if (ft_strncmp((buf + i), "\n\0", 2) == 0)
  {
  }
  else
    exit (printf("Error: Invalid element\n"));
}

char	*get_map_string(char *buf, int fd)
{
	char	*ret;
  char    *map;
	int		i;
	int		j;

  map = get_file(fd);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(map) + 1));
	if (!ret)
    {
      free(map);
		  return (NULL);
    }
	i = cpy_ret(ret, buf);
	j = 0;
	while (map[j] != 0)
	{
		ret[i] = map[j];
		j++;
		i++;
	}
	ret[i] = '\0';
  free(map);
	return (ret);
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
      {
        getb()->map_string = get_map_string(buf, fd);
        init_map_depth();
        getb()->map = ft_split(getb()->map_string, '\n');
      }
      free(buf);
    }
    close(fd);
    if (ft_strncmp(getb()->map_string, "\0", 1) == 0)
      exit(printf("Error: There is no map\n"));
}