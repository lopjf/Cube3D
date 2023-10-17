#include "cube.h"

static int	check_ext(char *s1)
{
	char	*s2;
	char	*s3;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	if (i < 5)
		return (0);
	i = 0;
	s2 = ft_strdup(&s1[ft_strlen(s1) - 4]);
	s3 = ft_strdup(&s1[ft_strlen(s1) - 5]);
	if (ft_strncmp(s2, ".cub", 4) == 0)
		i = 1;
	if (ft_strncmp(s3, "/.cub", 5) == 0)
		i = 0;
	free(s2);
	free(s3);
	return (i);
}

void	check_arg(int ac, char *av[])
{
	int	fd;

	if (ac != 2)
	{
		ft_printf("Error: This program needs 1 argument\n");
		exit(1);
	}
	if (check_ext(av[1]) == 0)
	{
		ft_printf("Error: This program takes a map in format *.cub\n");
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: The .cub map does not exist\n");
		exit(1);
	}
	close(fd);
}
