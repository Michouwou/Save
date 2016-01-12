# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/12 18:03:51 by mlevieux          #+#    #+#              #
#    Updated: 2016/01/12 18:21:33 by mlevieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = check_file.c ft_convert.c ft_core.c ft_display.c ft_erase_form.c \
	  ft_error.c ft_get_forms.c ft_is_already_in.c ft_main.c ft_min_tab.c \
	  ft_next_form.c ft_resolve.c ft_struct_1.c ft_struct_2.c main.c \
	  utiles.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	gcc -c -Wall -Wextra -Werror $(SRC)
	gcc $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
