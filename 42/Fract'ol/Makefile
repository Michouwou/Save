# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 20:25:26 by mlevieux          #+#    #+#              #
#    Updated: 2017/01/18 17:35:56 by mlevieux         ###   ########.fr        #
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
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all
