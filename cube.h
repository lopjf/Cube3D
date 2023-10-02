#ifndef CUBE_H
# define CUBE_H

# include "utils/libft/libft.h"
# include <utils/minilibx-linux/mlx.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

# define KEY_RA 65363
# define KEY_LA 65361
# define KEY_W 119
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97
# define KEY_ESC 65307

typedef struct s_data {
	// map elements
	char	*NOpath;
	char	*SOpath;
	char	*WEpath;
	char	*EApath;
	char	*Fpath;
	char	*Cpath;
}				t_data;

typedef struct s_libx {
	// libx management
	void	*mlx;
	void	*win;
	// elements textures and colors
	void	*NO;
	void	*SO;
	void	*WE;
	void	*EA;
	void	*F;
	void 	*C;
	int		img_width;
	int		img_height;
}				t_libx;

typedef struct s_base {
	char	*map_string;
	char	**map;
	int		map_depth;
	t_data	data;
	t_libx	libx;
}				t_base;

int		main(int ac, char *av[]);
void	check_arg(int ac, char *av[]);
void 	parse(char *map_name);

// free
void 	free_data();
void free_and_exit(char *str);

// init
t_base *getb(void);
void init_all();
void init_map_depth();
void init_libx();

// utils
int skip_spaces(char *buf, int i);

// check_map
void check_map();

// window.c
void	display_win();
int	close_win();
int	fetch_key(int keycode);


#endif