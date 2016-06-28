# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/11 17:30:16 by mlevieux          #+#    #+#              #
#    Updated: 2016/05/21 11:15:33 by mlevieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =   ft_check_doubles.c ft_direction.c ft_free.c ft_loop_stat.c ft_ops.c\
		ft_repush.c utils.c ft_core.c ft_display.c ft_get_min.c ft_move.c\
		ft_print_stack.c ft_special_case.c main.c ft_create_stack.c ft_error.c\
		ft_get_options.c ft_new_stack.c ft_push_back.c ft_error_loop.c

OBJ = $(SRC:.c=.o)

HEADERS = libft.h

HEADERPATH = includes/

LIBL = -lft

NAME = push_swap

all : $(NAME)

$(NAME) : $(SRC)
	make re -C Libft
	gcc -Wall -Werror -Wextra -c $(SRC) -I$(HEADERPATH)
	gcc -Wall -Werror -Wextra $(OBJ) -L Libft/ $(LIBL) -o $(NAME)

re : fclean all

.PHONY: clean fclean norme

clean :
	make clean -C Libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C Libft
	rm -rf $(NAME)

norme :
	norminette $(SRC)
