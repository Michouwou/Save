# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/14 11:15:47 by mlevieux          #+#    #+#              #
#    Updated: 2016/05/24 14:38:31 by mlevieux         ###   ########.fr        #
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
	echo "Compilation...\n"
	make re -C Libft/
	gcc -c $(SRC) -I includes/ -I.
	gcc -Wall -Werror -Wextra $(OBJ) -L Libft/ -lft -o $(NAME)

.PHONY: clean fclean norme

clean :
	echo "Cleaning...\n"
	make clean -C Libft/
	rm -rf $(OBJ)

fclean : clean
	echo "Cleaning everything...\n"
	make fclean -C Libft/
	rm -rf $(NAME)

re : fclean all
