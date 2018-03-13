# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 16:36:17 by wsabates          #+#    #+#              #
#    Updated: 2018/03/13 13:45:36 by vguerand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_NAME = init_struct.c ft_raycasting.c sol.c ciel.c mlx_pixel_put_to_img.c mur.c fps_counter.c parsing.c keyfunc.c main.c obj.c ft_exit.c ft_aff_obj.c

SRC_PATH = src

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

INC = libft/libft.a

CCFLAG = gcc -g -Wall -Werror -Wextra

LIB_FLAG = libft/libft.a minilibx_macos/libmlx.a

FLAGMLX = -framework OpenGL -framework Appkit -g

INCLUDE	= wolf.h \
		  libft/libft.h

all : $(NAME)

$(NAME): $(SRC)
		@echo Wolf3d compiled "\033[32m[ ✔ ]\033[00m"
	 	@(cd libft; make; cd ..)
		@(cd minilibx_macos; make; cd ..)
		@$(CCFLAG) $(LIB_FLAG) -o $@ $^ $(FLAGMLX)

%.o: %.c
	@$(CCFLAG) -c $< -o $@ -I

clean:
	@echo CLEAN compiled "\033[32m[ ✔ ]\033[00m"
	@(cd minilibx_macos; make clean; cd ..)

fclean: clean
	@echo FCLEAN compiled "\033[32m[ ✔ ]\033[00m"
	@(cd libft; make fclean; cd ..; rm -fv $(NAME))

re : fclean all

.PHONY: clean fclean re all
