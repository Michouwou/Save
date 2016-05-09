# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/25 16:57:31 by mlevieux          #+#    #+#              #
#    Updated: 2016/05/05 17:27:54 by mlevieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a # Nom de l'exec lib creee
CC = gcc # Compilateur
CFLAGS = -Wall -Werror -Wextra # Flags de compil'

INCDIR = libft
HEADERDIR = includes/
SRC = ft_alternate.c ft_call_percent.c ft_conv_float.c \
ft_get_greatest_modifier.c ft_move_index.c ft_transfer_wchar.c \
ft_apply_flag.c ft_call_pointer.c ft_conv_wchar.c ft_get_width.c \
ft_printf.c ft_transfer_wchars.c ft_base.c ft_call_wildcard.c \
ft_double_type.c ft_int_type.c ft_repstr.c ft_type_crossroad.c \
ft_call_char.c ft_call_wstring.c ft_free_list.c ft_is_format.c \
ft_round.c ft_call_errno.c ft_char_type.c \
ft_get_accuracy.c ft_is_modifier.c ft_set_length.c ft_call_float.c \
ft_check_fmt.c ft_get_args.c ft_is_valid.c ft_set_width.c \
ft_call_int.c ft_conv_exp.c ft_get_fmt.c ft_make_node.c ft_strset.c

OBJ = $(patsubst %c, %o, $(SRC))

HEADERS = $(addprefix $(HEADERDIR), $(patsubst %a, %h, $(NAME)))

all: $(NAME)

$(NAME): $(OBJ)
#	@echo "\033[0;31mConstruction de la librairie...\033[0;m\n"
	ar rc $(NAME) $(OBJ)
#	@echo "\033[0;32mOK!\033[0;m\n"
#	@echo "\033[0;31mCombinaison de la libft avec la libftprintf...\033[0;m\n"
	libtool -static -o $(NAME) libftprintf.a $(INCDIR)/libft.a
#	@echo "\033[0;32mOK!\033[0;m\n"
#	@echo "\033[0;31mIndexation...\033[0;m\n"
	ranlib $(NAME)
#	@echo "\033[0;32mOK!\033[0;m\n"

$(OBJ) :
#	@echo "\033[0;31mCompilation de la libft...\033[0;m\n"
	make re -C $(INCDIR)
#	@echo "\033[0;32mOK!\033[0;m\n"
#	@echo "\033[0;31mDeletion des objets pour la libft...\033[0;m\n"
	make clean -C $(INCDIR)
#	@echo "\033[0;32mOK!\033[0;m\n"
#	@echo "\033[0;31mCompilation des sources...\033[0;m\n"
	gcc -Wall -Werror -Wextra -c $(SRC) -I $(HEADERDIR)
#	@echo "\033[0;32mOK!\033[0;m\n"

clean:
#	@echo "\033[0;31mDeletion des objets...\033[0;m\n"
	rm -f $(OBJ)
#	@echo "\033[0;32mOK!\033[0;m\n"

fclean: clean
#	@echo "\033[0;31mDeletion de la libftprintf...\033[0;m\n"
	rm -f $(NAME)
#	@echo "\033[0;32mOK!\033[0;m\n"
#	@echo "\033[0;31mNettoyage de la libft...\033[0;m\n"
	make fclean -C $(INCDIR)
#	@echo "\033[0;32mOK!\033[0;m\n"

re: fclean all

norme :
	norminette $(SRC) $(HEADERS)

tests :
	@mkdir -p tests_result
	@gcc -w -o maintest_C maintests/maintest_C.c $(NAME) -I $(HEADERDIR)
	@gcc -w -o maintest_c maintests/maintest_c.c $(NAME) -I $(HEADERDIR)
	@gcc -w -o maintest_s maintests/maintest_s.c $(NAME) -I $(HEADERDIR)
	@gcc -w -o maintest_S maintests/maintest_S.c $(NAME) -I $(HEADERDIR)
	@gcc -w -o maintest_d maintests/maintest_d.c $(NAME) -I $(HEADERDIR)
	@gcc -w -o maintest_i maintests/maintest_i.c $(NAME) -I $(HEADERDIR)
	@gcc -w -o maintest_o maintests/maintest_o.c $(NAME) -I $(HEADERDIR)
	@gcc -w -o maintest_x maintests/maintest_x.c $(NAME) -I $(HEADERDIR)
	@gcc -w -o maintest_u maintests/maintest_u.c $(NAME) -I $(HEADERDIR)
	@gcc -w -o maintest_D maintests/maintest_D.c $(NAME) -I $(HEADERDIR)
	@gcc -w -o maintest_O maintests/maintest_O.c $(NAME) -I $(HEADERDIR)
	@gcc -w -o maintest_X maintests/maintest_X.c $(NAME) -I $(HEADERDIR)
	@gcc -w -o maintest_U maintests/maintest_U.c $(NAME) -I $(HEADERDIR)
	@gcc -w -o maintest_p maintests/maintest_p.c $(NAME) -I $(HEADERDIR)
	@gcc -w -o maintest_bonus maintests/maintest_bonus.c $(NAME) -I $(HEADERDIR)
	@gcc -w -o maintest_time maintests/maintest_time.c $(NAME) -I $(HEADERDIR)
	@./maintest_C > tests_result/maintest_C
	@./maintest_c > tests_result/maintest_c
	@./maintest_s > tests_result/maintest_s
	@./maintest_S > tests_result/maintest_S
	@./maintest_d > tests_result/maintest_d
	@./maintest_i > tests_result/maintest_i
	@./maintest_o > tests_result/maintest_o
	@./maintest_x > tests_result/maintest_x
	@./maintest_u > tests_result/maintest_u
	@./maintest_D > tests_result/maintest_D
	@./maintest_O > tests_result/maintest_O
	@./maintest_X > tests_result/maintest_X
	@./maintest_U > tests_result/maintest_U
	@./maintest_p > tests_result/maintest_p
	@./maintest_bonus > tests_result/maintest_bonus
	@./maintest_time > tests_result/maintest_time
	@rm -f maintest_C maintest_c maintest_s maintest_S maintest_d maintest_i \
		maintest_o maintest_u maintest_x maintest_D maintest_O maintest_U \
		maintest_X maintest_p maintest_time maintest_unit_failed \
		maintest_bonus
