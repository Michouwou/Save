# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/14 11:15:47 by mlevieux          #+#    #+#              #
#    Updated: 2016/03/14 12:35:56 by mlevieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_create_ant.c ft_free_everything.c ft_link_room.c ft_path_len.c \
	  	ft_block.c ft_create_path.c ft_get_ants.c ft_links_rooms.c \
		ft_print_move.c ft_build_path.c ft_create_room.c ft_get_rooms.c \
		ft_min_path.c ft_read_file.c ft_core.c ft_find_paths.c ft_iterate.c \
		ft_path_is_free.c get_next_line.c

OBJ = $(SRC:.c=.o)

HEADERS = lem_in.h get_next_line.h libft.h libftprintf.h

LIBPATH = ~/Save/Lem-in2/includes

LIBS = -lft -lftprintf

NAME = lem-in

all : makedir $(NAME)

$(NAME) : $(OBJ)
	@echo "Compilation..."
	@cc $(OBJ) -L $(LIBPATH) $(LIBS) -I $(HEADERS)

makedir :
	mkdir $(LIBPATH)
	cp ~/Save/ft_printf/*.a $(LIBPATH)

$(OBJ) : $(SRC) $(HEADERS)

.PHONY: clean fclean norme

clean :
	@echo "Cleaning..."
	@rm -f $(OBJ)

fclean : clean
	@echo "Cleaning everything..."
	@rm -rf $(NAME) $(LIBPATH)

norme : $(SRC) $(HEADERS)
	@touch normfile.txt
	@norminette $(SRC) $(HEADERS) > normfile.txt
	@echo "File 'normfile.txt' created."
