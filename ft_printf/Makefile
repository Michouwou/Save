# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/24 09:30:57 by mlevieux          #+#    #+#              #
#    Updated: 2016/02/24 11:48:52 by mlevieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_alternate.c ft_conv_exp.c ft_get_star.c ft_strset.c ft_wstrsub.c \
      ft_apply_flag.c ft_conv_float.c ft_get_width.c ft_strtoupper.c \
      ft_base.c ft_conv_wchar.c ft_int_apply_mod.c ft_transfer_wchar.c \
	  ft_call_char.c ft_error.c ft_is_flag.c ft_transfer_wchars.c \
      ft_call_errno.c ft_find_form.c ft_is_format.c ft_watoi.c \
      ft_call_float.c ft_float_apply_mod.c ft_is_mod.c ft_wbzero.c \
      ft_call_int.c ft_free_list.c ft_move_index.c ft_what_type.c \
      ft_call_pointer.c ft_get_accuracy.c ft_printf.c ft_wstrcpy.c \
      ft_get_arg.c ft_putwstr.c ft_wstrdup.c ft_get_flag.c ft_repstr.c \
      ft_wstring_apply_mod.c ft_call_wstring.c ft_get_float.c ft_round.c \
      ft_wstrlen.c ft_char_apply_mod.c ft_get_int.c ft_set_length.c \
      ft_wstrnew.c ft_check_format.c ft_get_mod.c ft_set_width.c \
      ft_wstrset.c ft_alternate.c ft_conv_exp.c ft_get_star.c ft_strset.c \
      ft_wstrsub.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	gcc -c -Wall -Werror -Wextra $(SRC)
	ar rc $(NAME) $(OBJ)

clean :
	rm -f $(OBJ) libftprintf.h.gch

fclean : clean
	rm -f $(NAME)

re : fclean all

norme :
	norminette $(SRC) libftprintf.h
