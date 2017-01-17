# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 20:25:26 by mlevieux          #+#    #+#              #
#    Updated: 2017/01/17 21:56:26 by mlevieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c fract.c complex.c

INC = Libft/

OBJ = $(SRC:.c=.o)

LIBDIR = Libft/

LIBS = -lft

all : $(NAME)

$(NAME) :
		gcc -Wall -Wextra -Werror $(SRC) -I $(INC) -L $(LIBDIR) $(LIBS) -lmlx -framework OpenGL -framework Appkit

clean :
		make clean -C ft_printf/
		rm -f $(OBJ)

fclean : clean
		make fclean -C ft_printf/
		rm -f $(NAME)

re : fclean all
