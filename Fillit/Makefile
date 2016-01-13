# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/12 18:03:51 by mlevieux          #+#    #+#              #
#    Updated: 2016/01/13 10:51:06 by mlevieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = check_file.c ft_convert.c ft_core.c ft_display.c ft_erase_form.c \
	  ft_error.c ft_get_forms.c ft_is_already_in.c ft_main.c ft_min_tab.c \
	  ft_next_form.c ft_resolve.c ft_struct_1.c ft_struct_2.c main.c \
	  utiles.c ft_is_stuck.c

OBJ = $(SRC:.c=.o)

PATH_TEST = ./tests_correct/

PATH_FAIL = ./tests_error/

all : $(NAME)

$(NAME) :
	gcc -c -Wall -Wextra -Werror $(SRC)
	gcc $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

norme :
	norminette $(SRC)

test_ok :
	./$(NAME) $(PATH_TEST)test_1
	./$(NAME) $(PATH_TEST)test_2
	./$(NAME) $(PATH_TEST)test_3
	./$(NAME) $(PATH_TEST)test_4
	./$(NAME) $(PATH_TEST)test_5
	./$(NAME) $(PATH_TEST)test_6
	./$(NAME) $(PATH_TEST)test_7
	./$(NAME) $(PATH_TEST)test_8
	./$(NAME) $(PATH_TEST)test_9
	./$(NAME) $(PATH_TEST)test_10
	./$(NAME) $(PATH_TEST)test_11

fail :
	./$(NAME) $(PATH_FAIL)error_no_end_newline
	./$(NAME) $(PATH_FAIL)error_not_valid_form_3
	./$(NAME) $(PATH_FAIL)error_one_more_line_on_form
	./$(NAME) $(PATH_FAIL)error_starting_space
	./$(NAME) $(PATH_FAIL)error_no_form_at_all
	./$(NAME) $(PATH_FAIL)error_one_less_line_on_form
	./$(NAME) $(PATH_FAIL)error_one_more_newline
	./$(NAME) $(PATH_FAIL)error_too_many_forms
	./$(NAME) $(PATH_FAIL)error_not_valid_form_1
	./$(NAME) $(PATH_FAIL)error_one_less_point
	./$(NAME) $(PATH_FAIL)error_one_more_point
	./$(NAME) $(PATH_FAIL)error_not_valid_form_2
	./$(NAME) $(PATH_FAIL)error_one_more_end_newline
	./$(NAME) $(PATH_FAIL)error_space_in_the_middle
	./$(NAME) $(PATH_FAIL)error_form_exception
