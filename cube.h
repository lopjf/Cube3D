#ifndef CUBE_H
# define CUBE_H

# include "utils/libft/libft.h"
# include <utils/minilibx-linux/mlx.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97
# define KEY_ESC 65307

typedef struct s_data {
	// map elements
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
}				t_data;

typedef struct s_base {
	char	**map;
	int		map_depth;
	t_data	data;
}				t_base;

int		main(int ac, char *av[]);
void	check_arg(int ac, char *av[]);
void 	init_all();
t_base *getb(void);
void 	parse(char *map_name);
void 	free_all();

// utils
int skip_spaces(char *buf, int i);

// check_map
void check_map();

#endif