# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/14 11:15:47 by mlevieux          #+#    #+#              #
#    Updated: 2016/06/08 15:11:47 by mlevieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_create_ant.c ft_free_everything.c ft_link_room.c ft_path_len.c \
		ft_block.c ft_create_path.c ft_get_ants.c ft_links_rooms.c \
		ft_print_move.c ft_build_path.c ft_create_room.c ft_get_rooms.c \
		ft_min_path.c ft_read_file.c ft_core.c ft_find_paths.c ft_iterate.c \
		ft_path_is_free.c ft_paths_coeff.c get_next_line.c \
		ft_check_coordinates.c main.c

OBJ = $(SRC:.c=.o)

NAME = lem-in

all : $(NAME)

$(NAME) :
	@echo "Compilation...\n"
	@make -C Libft/
	@gcc -Wall -Werror -Wextra -c $(SRC) -I includes/ -I.
	@gcc -Wall -Werror -Wextra $(OBJ) -L Libft/ -lft -o $(NAME)
	@echo "\033[0;32mOK!\n\033[0;m"

.PHONY: clean fclean norme

clean :
	@echo "Cleaning...\n"
	@make clean -C Libft/
	@rm -rf $(OBJ)

fclean : clean
	@echo "Cleaning everything...\n"
	@make fclean -C Libft/
	@rm -rf $(NAME)

re : fclean all

norme :
	@norminette **/**.[ch]

test :
	@echo "Building the generator...\n"
	@echo "if [ ! -d gen ]\nthen\n\
	\tgit clone https://github.com/cmehay/lem-in_generator.git gen\n\
	else\n\tcd gen git pull\nfi" > git.sh
	@sh git.sh
	@make -C gen
	@cp gen/lem-in_gen .
	@./lem-in_gen 15 5 > file_test
	@./lem-in < file_test
	@sleep 1
	@echo "\n"
	@./lem-in_gen 15 10 > file_test
	@./lem-in < file_test
	@sleep 1
	@echo "\n"
	@./lem-in_gen 15 11 > file_test
	@./lem-in < file_test
	@sleep 1
	@echo "\n"
	@./lem-in_gen 15 12 > file_test
	@./lem-in < file_test
	@sleep 1
	@echo "\n"
	@./lem-in_gen 15 15 > file_test
	@./lem-in < file_test
	@sleep 1
	@echo "\n"
	@./lem-in_gen 15 20 > file_test
	@./lem-in < file_test
	@sleep 1
	@echo "\n"
	@./lem-in_gen 15 3 > file_test
	@./lem-in < file_test
	@sleep 1
	@echo "\n"
	@./lem-in_gen 15 8 > file_test
	@./lem-in < file_test
	@sleep 1
	@echo "\n"
	@./lem-in_gen 15 17 > file_test
	@./lem-in < file_test
	@sleep 1
	@echo "\n"
	@./lem-in_gen 15 15 > file_test
	@./lem-in < file_test
	@sleep 1
	@echo "\n"
	@./lem-in_gen 15 9 > file_test
	@./lem-in < file_test
	@sleep 1
	@echo "\n"
	@./lem-in_gen 15 5 > file_test
	@./lem-in < file_test
	@sleep 1
	@echo "\n"
	@./lem-in_gen 15 7 > file_test
	@./lem-in < file_test
	@sleep 1
	@echo "\n"
	@./lem-in_gen 15 2 > file_test
	@./lem-in < file_test
	@sleep 1
	@echo "\n"
	@rm -rf file_test gen lem-in_gen git.sh
	@echo "Tests OK!\n"
