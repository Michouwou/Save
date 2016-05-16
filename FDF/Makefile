# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/16 17:19:03 by mlevieux          #+#    #+#              #
#    Updated: 2016/05/16 17:35:02 by mlevieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_MINILIBX = 
DIR_MINILIBIX = ~/Downloads/minilibx
CFLAGS += -I $(DIR_MINILIBIX)/
LDFLAGS += -L /usr/X11/lib -lmlx_x86_64 -lXext -lX11

all :
	gcc test.c $(CFLAGS) $(LDFLAGS)
