# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/04 13:47:25 by mlevieux          #+#    #+#              #
#    Updated: 2016/09/06 23:04:27 by mlevieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libj_list.a

SRC = jlst_compact.c jlst_del_list.c jlst_get_index.c jlst_is_sorted.c \
	  jlst_new.c jlst_push_back.c  jlst_sort.c ft_memcpy.c jlst_create.c \
	  jlst_del_node.c jlst_get_size.c jlst_length.c jlst_nforward.c \
	  jlst_push_front.c jlst_datacpy.c jlst_from_tab.c jlst_in_jlst.c \
	  jlst_merge.c jlst_node.c jlst_resize.c jlst_add.c jlst_del_data.c \
	  jlst_get_data.c jlst_instances.c jlst_nbackward.c jlst_nodecpy.c \
	  jlst_sed.c jlst_reverse.c jlst_quick_sort.c jlst_full_node.c \
	  jlst_add_data.c jlst_map.c jlst_push.c jlst_to_tree.c

OBJ = $(SRC:.c=.o)

all : $(SRC) $(NAME)

$(NAME) :
	gcc -c -Wall -Werror -Wextra $(SRC) -I.
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
