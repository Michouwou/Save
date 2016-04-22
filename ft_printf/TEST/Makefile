# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/24 09:30:57 by mlevieux          #+#    #+#              #
#    Updated: 2016/03/24 21:27:47 by mlevieux         ###   ########.fr        #
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
      ft_wstrsub.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
	  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
	  ft_memccpy.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memdel.c \
	  ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
	  ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
	  ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
	  ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
	  ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
	  ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
	  ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	  ft_tolower.c ft_toupper.c


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
