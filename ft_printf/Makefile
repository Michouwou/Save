# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/06 17:30:45 by mlevieux          #+#    #+#              #
#    Updated: 2016/01/06 19:04:42 by mlevieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_address.c ft_base.c ft_conv_wchar.c ft_find_form.c ft_integers.c \
	  ft_isint.c ft_putfloat.c ft_putnbr.c ft_putstr.c ft_repstr.c \
	  ft_upstring.c ft_others.c libftprintf.h

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	gcc -c -Wall -Wextra -Werror $(SRC) -L. -lft
	ar rc $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
