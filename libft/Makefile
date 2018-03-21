# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:03:16 by vguerand          #+#    #+#              #
#    Updated: 2018/03/20 13:56:26 by wsabates         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

COMPIL = gcc

FLAG = -Wall -Wextra -Werror
OPT = -c

C_HEADERS = libft.h

SRCS = ft_nbrlen.c ft_strnjoin.c ft_strndup.c ft_tabint.c get_next_line.c ft_nb_mots.c ft_nb_ltr.c ft_index_mot.c ft_lstlen.c ft_isalnum.c ft_isdigit.c ft_lstadd.c ft_lstiter.c ft_memalloc.c ft_memcmp.c ft_memmove.c ft_putchar_fd.c ft_putnbr.c ft_putstr_fd.c ft_strclr.c ft_strdel.c ft_striter.c ft_strlcat.c ft_strmapi.c ft_strncpy.c ft_strnstr.c ft_strstr.c ft_tolower.c ft_atoi.c ft_isalpha.c ft_isprint.c ft_lstdel.c ft_lstmap.c ft_memccpy.c ft_memcpy.c ft_memset.c ft_putendl.c ft_putnbr_fd.c ft_strcat.c ft_strcmp.c ft_strdup.c ft_striteri.c ft_strlen.c ft_strncat.c ft_strnequ.c ft_strrchr.c ft_strsub.c ft_toupper.c ft_bzero.c ft_isascii.c ft_itoa.c ft_lstdelone.c ft_lstnew.c ft_memchr.c ft_memdel.c ft_putchar.c ft_putendl_fd.c ft_putstr.c ft_strchr.c ft_strcpy.c ft_strequ.c ft_strjoin.c ft_strmap.c ft_strncmp.c ft_strnew.c ft_strsplit.c ft_strtrim.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

./%.o: %.c
	@gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)



clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
