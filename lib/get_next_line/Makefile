# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 09:44:14 by emgul             #+#    #+#              #
#    Updated: 2024/04/11 07:26:58 by emgul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	get_next_line \
			get_next_line_utils

NAME	=	get_next_line.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rcs
RM		=	rm -f

SRCS	=	$(SRCS_PATH)$(addsuffix .c, $(FILES))
OBJS 	=	$(OBJS_PATH)$(addsuffix .o, $(FILES))

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	@$(AR) $@ $^

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: clean all

.PHONY: all re fclean clean
