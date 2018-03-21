# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/17 16:14:51 by vguerand          #+#    #+#              #
#    Updated: 2018/03/20 13:58:28 by wsabates         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_NAME = init_struct.c ft_raycasting.c floor.c sky.c mlx_pixel_put_to_img.c \
			mur.c fps_counter.c parsing.c keyfunc.c main.c obj.c ft_exit.c \
			ft_aff_obj.c ft_ligne.c mouse_hook.c menu.c raycasting_commands.c\
			init_texture.c keyfunc_move.c init_obj.c shooting.c pos_spawn.c

SRC_PATH = src/

OBJ = $(patsubst %.c,%.o, $(addprefix $(SRC_PATH), $(SRC_NAME)))

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB_FLAG = libft/libft.a minilibx_macos/libmlx.a

FLAGMLX = -framework OpenGL -framework Appkit

HEAD	= include/wolf.h

all : $(NAME)

$(NAME): $(OBJ) $(HEAD)
		@echo Wolf3d compiled "\033[32m[ ✔ ]\033[00m"
		@make -C libft/
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

clean:
	@echo CLEAN compiled "\033[32m[ ✔ ]\033[00m"
	@make -C libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo FCLEAN compiled "\033[32m[ ✔ ]\033[00m"
	@make -C libft fclean
	@/bin/rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re all
