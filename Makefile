# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguerand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/24 22:43:05 by vguerand          #+#    #+#              #
#    Updated: 2018/05/24 22:49:51 by vguerand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_NAME = init_struct.c ft_raycasting.c floor.c mlx_pixel_put_to_img.c \
			mur.c fps_counter.c parsing.c keyfunc.c main.c obj.c ft_exit.c \
			ft_aff_obj.c ft_ligne.c mouse_hook.c multi_thread.c\
			init_texture.c keyfunc_move.c init_obj.c pos_spawn.c\

SRC_PATH = src/

lib = -lmlx -Lminilibx_macos

OBJ = $(patsubst %.c,%.o, $(addprefix $(SRC_PATH), $(SRC_NAME)))

CC = gcc

.SILENT:

CFLAGS = -Wall -Werror -Wextra

LIB_FLAG = libft/libft.a minilibx_macos/libmlx.a

FLAGMLX = -framework OpenGL -framework Appkit

HEAD	= include/wolf.h

all : $(NAME)

$(NAME): $(OBJ)
		@make -C libft/
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -Lminilibx_macos -framework OpenGL -framework AppKit
		@echo "\033[0;32m[OK] \033[0m\033[0;33m Compiling file:\033[0m " $@
clean:
	@make -C libft clean
	@echo "\033[0;32m[OK] \033[0m\033[0;33m :\033[0m " $@
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@echo "\033[0;32m[OK] \033[0m\033[0;33m :\033[0m " $@
	@/bin/rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re all
