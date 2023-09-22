#include "cube.h"

static char	*get_map(int fd)
{
	char	*map;

	map = get_file(fd);
	close(fd);
	return (map);
}

char	*get_whole_map(char *buf, int fd)
{
	char	*ret;
    char    *map;
	int		i;
	int		j;

    map = get_map(fd);
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