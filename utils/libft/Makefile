# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loris <loris@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 14:54:38 by lpenelon          #+#    #+#              #
#    Updated: 2023/09/21 21:01:21 by loris            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c ft_memset.c ft_revert.c\
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c \
					ft_striteri.c ft_putnbru_fd.c \
					ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
					ft_printf.c ft_printf_funcs1.c ft_printf_funcs2.c get_file.c \
					ft_swap_char.c get_next_line.c get_next_line_utils.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
RUN				= ar rcs

%.o: %.c
	$(CC) -c $(CFLAGS) -I headers $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(RUN) $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)