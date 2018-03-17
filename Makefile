# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/17 16:14:51 by vguerand          #+#    #+#              #
#    Updated: 2018/03/17 16:17:20 by vguerand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_NAME = init_struct.c ft_raycasting.c sol.c ciel.c mlx_pixel_put_to_img.c mur.c fps_counter.c parsing.c keyfunc.c main.c obj.c ft_exit.c ft_aff_obj.c ft_ligne.c mouse_hook.c menu.c

SRC_PATH = src/

OBJ = $(patsubst %.c,%.o, $(addprefix $(SRC_PATH), $(SRC_NAME)))

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB_FLAG = libft/libft.a minilibx_macos/libmlx.a

FLAGMLX = -framework OpenGL -framework Appkit

INCLUDE	= include/wolf.h \
		  libft/libft.h

all : $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
		@echo Wolf3d compiled "\033[32m[ ✔ ]\033[00m"
		make -C libft/
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

clean:
	@echo CLEAN compiled "\033[32m[ ✔ ]\033[00m"
	make -C libft clean
	/bin/rm -f $(OBJ)

fclean: clean
	@echo FCLEAN compiled "\033[32m[ ✔ ]\033[00m"
	make -C libft fclean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re all
