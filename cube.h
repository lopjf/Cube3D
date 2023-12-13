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
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97
# define KEY_ESC 65307
# define ROT_SPEED 0.2
# define WIN_H 480
# define WIN_W 640
# define TEX_H 64
# define TEX_W 64

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
plane: surface of camera screen and vision length
nr_rays: amount of rays
ray_dir_ : x and y direction of ray
map_ : the square the ray is currently inside (int coordniates)
side_dist_ : distance of ray from first pos to nxt x and y-side
delta_dist_ : distance to next x and y-side
step_ : direction of next step, always 1 or -1 (if negative or positive)
perp_wall_dist: distance wall_collision from camera plane
*/
typedef struct s_dda {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	char			dir;
	double	camera_x;
	int				nr_rays; //evtl not needed
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	perp_wall_dist;
	int		hit;
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

//map_depth: y-achsis
typedef struct s_base {
	char	*map_string;
	char	**map;
	int		map_depth;
	int		map_width;
	t_data	data;
	t_libx	libx;
	t_dda	*dda;
}				t_base;

int		main(int ac, char *av[]);
void	check_arg(int ac, char *av[]);

// parser.c
void	parse(char *map_name, t_base *b, int fd, char *buf);

// free.c
void	free_data(void);
void	free_and_exit(char *str);

// init.c
t_base	*getb(void);
t_dda	*get_dda(void);
void	init_map_depth(void);
void	init_map_width(void);
void	init_data(void);
void	init_libx(void);
void	init_dda(void);

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
void	update_pos(int keycode);
void	update_dir(int keycode);
void	update_plane(int keycode);
int		get_rgb(char *rgb);
void	start_dda(void);
void	calc_line(t_base *base, int x);
void	draw_line(int draw_start, int draw_end, t_base *base, int x);
void	paint_background(t_base *base);

// check_elements.c
void	check_rgb(void);

#endif
