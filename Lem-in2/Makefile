
SRC=    ft_block.c ft_create_room.c ft_iterate.c ft_path_len.c ft_build_path.c \
        ft_find_paths.c ft_link_room.c ft_print_move.c ft_core.c ft_free_everything.c \
        ft_links_rooms.c ft_read_file.c ft_create_ant.c ft_get_ants.c ft_min_path.c \
        ft_create_path.c ft_get_rooms.c ft_path_is_free.c get_next_line.c

HEADER= lem_in.h get_next_line.h

OBJ=    $(SRC:.c=.o)

LIBS=   -lft -lftprintf

EXEC=   lem-in



all : obj exec clean

obj :
    gcc -Wall -Wextra -Werror -c $(SRC) $(HEADER)
    
exec : obj
    gcc -o $(EXEC) $(OBJ) -L. $(LIBS)

clean :
    rm -f $(OBJ)
    
fclean : clean
    rm -f $(EXEC)
    
norme :
    norminette $(SRC) $(HEADER)