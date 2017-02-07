# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 17:37:20 by mlevieux          #+#    #+#              #
#    Updated: 2017/02/07 18:49:05 by mlevieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpool.a

SRC = pool_init.c pool_init2.c

INC = pool.h

OBJ = $(SRC:.c=.o)

LIBS = libft.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRC) -I. $(INC)
	ar rc $(NAME) $(OBJ)
	libtool -static -o $(NAME) $(NAME) $(LIBS)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
