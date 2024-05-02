# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 09:44:14 by emgul             #+#    #+#              #
#    Updated: 2023/12/10 19:45:27 by emgul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	ft_atoi \
		ft_bzero \
		ft_calloc \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_itoa \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_putchar_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_putstr_fd \
		ft_split \
		ft_strchr \
		ft_strdup \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strmapi \
		ft_strncmp \
		ft_strnstr \
		ft_strrchr \
		ft_strtrim \
		ft_substr \
		ft_tolower \
		ft_toupper

BONUS_FILES	=	ft_lstadd_back \
			ft_lstadd_front \
			ft_lstclear \
			ft_lstdelone \
			ft_lstiter \
			ft_lstlast \
			ft_lstmap \
			ft_lstnew \
			ft_lstsize \

NAME	=	libft.a
CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR	=	ar rcs
RM	=	rm -f

SRCS	=	$(SRCS_PATH)$(addsuffix .c, $(FILES))
BONUS_SRCS	=	$(SRCS_PATH), $(addsuffix .c, $(BONUS_FILES))

OBJS =	$(OBJS_PATH)$(addsuffix .o, $(FILES))
BONUS_OBJS = $(OBJS_PATH)$(addsuffix .o, $(BONUS_FILES))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(BONUS_OBJS)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all re fclean clean
