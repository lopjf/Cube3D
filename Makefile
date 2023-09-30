NAME = cube

SRCS = cube.c args_checker.c init.c parser.c free.c utils.c check_map.c window.c

LIBFT_A = libft.a
LIBFT_DIR = utils/libft/
LIBFT  = $(addprefix $(LIBFT_DIR), $(LIBFT_A))

LIBX = ./utils/minilibx-linux/libmlx.a

OBJS = $(SRCS:.c=.o)
	
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -I.
INCLUDE			= -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz #-fsanitize=address

%.o: %.c
	gcc $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	gcc $(FLAGS) $(OBJS) $(LIBFT) $(LIBX) $(INCLUDE) -o $(NAME)

$(OBJS): $(SRCS)
	gcc $(FLAGS) -c $(SRCS)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(OBJS)

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

.PHONY: all clean fclean re