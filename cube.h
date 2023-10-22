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

	// map elements
typedef struct s_data {
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*f_path;
	char	*c_path;
}				t_data;

/*
pos: X and Y starting position
dir: direction and length of view
plane: surface of camera screen amnd vision length
*/
typedef struct s_dda {
	int posX;
	int	posY;
	int	dirX;
	int	dirY;
	int planeX;
	int planeY;
}				t_dda;

	// libx management & elements textures and colors
typedef struct s_libx {
	void	*mlx;
	void	*win;
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	void	*f;
	void	*c;
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
void	parse(char *map_name);

// free.c
void	free_data(void);
void	free_and_exit(char *str);

// init.c
t_base	*getb(void);
void	init_all(void);
void	init_map_depth(void);
void	init_libx(void);

// utils.c
int		skip_spaces(char *buf, int i);

// check_map.c & check_map2.c
void	check_map(void);
void	check_first_last_lines(void);
int		is_player_or_zero(int i, int j);
int		v(int i, int j);

// window.c
void	display_win(void);
int		close_win(void);
int		fetch_key(int keycode);

// check_elements.c
void	check_rgb(void);

#endif
