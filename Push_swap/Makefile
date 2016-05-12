# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/11 17:30:16 by mlevieux          #+#    #+#              #
#    Updated: 2016/05/12 12:33:00 by mlevieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =   ft_check_doubles.c ft_direction.c ft_free.c ft_loop_stat.c ft_ops.c\
		ft_repush.c utils.c ft_core.c ft_display.c ft_get_min.c ft_move.c\
		ft_print_stack.c ft_special_case.c main.c ft_create_stack.c ft_error.c\
		ft_get_options.c ft_new_stack.c ft_push_back.c ft_error_loop.c

OBJ = $(SRC:.c=.o)

HEADERS = libft.h libftprintf.h

HEADERPATH = includes/

LIBPATH = libs/

LIBP = -lftprintf

LIBL = -lft

NAME = push_swap

all : $(NAME)

$(NAME) : $(SRC)
	make re -C $(LIBPATH)ft_printf && make re -C $(LIBPATH)Libft
	echo "Compilation...\n"
	gcc -Wall -Werror -Wextra -c $(SRC) -I$(HEADERPATH)
	gcc -Wall -Werror -Wextra $(OBJ) -L $(LIBPATH)/ft_printf $(LIBP) -L $(LIBPATH)/Libft $(LIBL) -o $(NAME)

re : fclean all

.PHONY: clean fclean norme

clean :
	@echo "Cleaning...\n"
	@rm -rf $(OBJ)

fclean : clean
	@echo "Cleaning everything...\n"
	@rm -rf $(NAME)

norme :
	@touch normfile.txt
	@norminette $(SRC) > normfile.txt
	@echo "File 'normfile.txt' created.\n"
