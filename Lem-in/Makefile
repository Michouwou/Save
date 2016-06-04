# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/14 11:15:47 by mlevieux          #+#    #+#              #
#    Updated: 2016/06/04 13:24:05 by mlevieux         ###   ########.fr        #
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

test :
	./lem-in < tests/test_1
	@echo "\n"
	@read
	./lem-in < tests/test_2
	@echo "\n"
	@read
	./lem-in < tests/test_3
	@echo "\n"
	@read
	./lem-in < tests/test_4
	@echo "\n"
	@read
	./lem-in < tests/test_5
	@echo "\n"
	@read
	./lem-in < tests/test_6
	@echo "\n"
	@read
	./lem-in < tests/test_7
	@echo "\n"
	@read
	./lem-in < tests/test_8
	@echo "\n"
	@read
	./lem-in < tests/test_9
	@echo "\n"
	@read
	./lem-in < tests/test_missing_coordinate
	@echo "\n"
	@read
	./lem-in < tests/test_no_parallel
	@echo "\n"
	@read
	./lem-in < tests/test_trailing_space_end_of_line
	@echo "\n"
	@read
	./lem-in < tests/test_negative_ants
	@echo "\n"
	@read
	./lem-in < tests/test_no_start
	@echo "\n"
	@read
	./lem-in < tests/test_twice_same_line
	@echo "\n"
	@read
	./lem-in < tests/test_comments_and_sharp_room_name
	@echo "\n"
	@read
	./lem-in < tests/test_negative_coordinates
	@echo "\n"
	@read
	./lem-in < tests/test_out_int
	@echo "\n"
	@read
	./lem-in < tests/test_two_ends
	@echo "\n"
	@read
	./lem-in < tests/test_dash_beginning_of_line
	@echo "\n"
	@read
	./lem-in < tests/test_newline_line5
	@echo "\n"
	@read
	./lem-in < tests/test_rooms_same_place
	@echo "\n"
	@read
	./lem-in < tests/test_two_rooms_same_name
	@echo "\n"
	@read
	./lem-in < tests/test_dash_end_of_line
	@echo "\n"
	@read
	./lem-in < tests/test_no_ants
	@echo "\n"
	@read
	./lem-in < tests/test_start_not_linked
	@echo "\n"
	@read
	./lem-in < tests/test_two_starts
	@echo "\n"
	@read
	./lem-in < tests/test_empty_file
	@echo "\n"
	@read
	./lem-in < tests/test_no_end
	@echo "\n"
	@read
	./lem-in < tests/test_tab_before_link
	@echo "\n"
	@read
	./lem-in < tests/test_wrong_name
	@echo "\n"
	@read
	./lem-in < tests/test_half_link
	@echo "\n"
	@read
	./lem-in < tests/test_no_links
	@echo "\n"
	@read
	./lem-in < tests/test_trailing_space
