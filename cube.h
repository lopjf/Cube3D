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

	void	*wall;
	void	*empty;
	void	*exit;
	void	*player;
	void	*collectible;
	int		img_width;
	int		img_height;
	int		s_pos;
}				t_data;

typedef struct s_base {
	void	*mlx;
	void	*win;
	char	*map;
	t_data	img;
}				t_base;

int		win_size(char *map, char c);
char	*get_map(char *map_name);
int		check_ext(char *s1);
int		main(int ac, char *av[]);
int		check_shape(char *map, int e, int c, int p);
int		check_valid_map(char *map);
int		display_game(t_base *base, int i, int x, int y);
int		move(int keycode, t_base *base);
int		close_victory(t_base *base);
void		check_arg(int ac, char *av[]);
void parse(char *map_name, t_base *base);
void free_all(t_base *base);
void init(t_base *base);

#endif