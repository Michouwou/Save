# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/25 16:57:31 by mlevieux          #+#    #+#              #
#    Updated: 2016/04/25 17:22:49 by mlevieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a


all : $(NAME)

$(NAME) :
	gcc -c ft_printf.c
	ar rc $(NAME) ft_printf.o libft.a libft.h

clean :
	rm -rf ft_printf.o

fclean : clean
	rm -rf libftprintf.a

re : fclean all
