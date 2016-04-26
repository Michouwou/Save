# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/25 16:57:31 by mlevieux          #+#    #+#              #
#    Updated: 2016/04/26 16:00:48 by mlevieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a # Nom de l'exec lib creee
CC = gcc # Compilateur
CFLAGS = -Wall -Werror -Wextra # Flags de compil'

INC = libft/
SRC = ft_printf.c # Les sources
OBJ = $(patsubst %c, %o, $(SRC))


all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;31mConstruction de la librairie...\033[0;m\n"
	@ar rc $(NAME) $(OBJ)
	@echo "\033[0;32mOK!\033[0;m\n"
	@echo "\033[0;31mCombinaison de la libft avec la libftprintf...\033[0;m\n"
	@libtool -static -o $(NAME) libftprintf.a $(INC)libft.a
	@echo "\033[0;32mOK!\033[0;m\n"
	@echo "\033[0;31mIndexation...\033[0;m\n"
	@ranlib $(NAME)
	@echo "\033[0;32mOK!\033[0;m\n"

$(OBJ) : lib
	@echo "\033[0;31mCompilation des sources...\033[0;m\n"
	@gcc -c $(SRC)
	@echo "\033[0;32mOK!\033[0;m\n"

lib :
	@echo "\033[0;31mCompilation de la libft...\033[0;m\n"
	@make re -C $(INC)
	@echo "\033[0;32mOK!\033[0;m\n"
	@echo "\033[0;31mDeletion des objets pour la libft...\033[0;m\n"
	@make clean -C $(INC)
	@echo "\033[0;32mOK!\033[0;m\n"

clean:
	@echo "\033[0;31mDeletion des objets...\033[0;m\n"
	@rm -f $(OBJ)
	@echo "\033[0;32mOK!\033[0;m\n"

fclean: clean
	@echo "\033[0;31mDeletion de la libftprintf...\033[0;m\n"
	@rm -f $(NAME)
	@echo "\033[0;32mOK!\033[0;m\n"
	@echo "\033[0;31mNettoyage de la libft...\033[0;m\n"
	@make fclean -C $(INC)
	@echo "\033[0;32mOK!\033[0;m\n"
	
re: fclean all
