NAME = cube

SRCS =	cube.c parser/args_checker.c data/init_base.c parser/parser.c data/free.c \
		parser/parser_utils.c parser/check_map.c parser/check_map2.c window/window.c \
		parser/check_rgb.c data/init_dda.c window/move.c window/raycaster.c

LIBFT_A = libft.a
LIBFT_DIR = utils/libft/
LIBFT  = $(addprefix $(LIBFT_DIR), $(LIBFT_A))

LIBX = ./utils/minilibx-linux/libmlx.a

OBJS = $(SRCS:.c=.o)

RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -I.
INCLUDE			= -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -fsanitize=address

%.o: %.c
	gcc $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	gcc $(FLAGS) $(OBJS) $(LIBFT) $(LIBX) $(INCLUDE) -o $(NAME)

#$(OBJS): $(SRCS)
#	gcc $(FLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(OBJS)

re: fclean all

# Leak checker without leaks from libx :D / not working
VALGRIND_CMD = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
PROGRAM = ./cube maps/valid/map2.cub
VALGRIND_LOG = valgrind.txt
l: $(NAME)
	$(VALGRIND_CMD) --log-file=$(VALGRIND_LOG) $(PROGRAM) 2>&1 | grep -v 'libx'

invalid: $(NAME)
	./cube maps/invalid/duplicate_player.cub || true
	./cube maps/invalid/empty_line.cub || true
	./cube maps/invalid/empty.cub || true
	./cube maps/invalid/foo.txt || true
	./cube maps/invalid/invalid_rgb.cub || true
	./cube maps/invalid/invalid_rgb2.cub || true
	./cube maps/invalid/invalid_textures.cub || true
	./cube maps/invalid/missing_texture.cub || true
	./cube maps/invalid/no_ceiling_rgb.cub || true
	./cube maps/invalid/no_ceiling.cub || true
	./cube maps/invalid/no_floor_rgb.cub || true
	./cube maps/invalid/no_floor.cub || true
	./cube maps/invalid/no_player.cub || true
	./cube maps/invalid/out_of_map_elements.cub || true
	./cube maps/invalid/player_on_borders.cub || true
	./cube maps/invalid/unclosed_map.cub || true
	./cube maps/invalid/unknown_char.cub || true

.PHONY: all clean fclean re
