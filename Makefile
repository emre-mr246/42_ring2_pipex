# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 07:09:36 by emgul             #+#    #+#              #
#    Updated: 2024/04/27 16:09:45 by emgul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES			=	pipex \
					utils

BONUS_FILES		=	pipex_bonus \
					utils_bonus

NAME			=	pipex.a
BONUS_NAME		=	pipex_bonus.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -I lib/libft/ -I lib/get_next_line/ 
AR				=	ar rcs
RM				=	rm -f

LIBFT_PATH		=	lib/libft/
LIBFT			=	$(LIBFT_PATH)libft.a
GNL_PATH		=	lib/get_next_line/
GNL				=	$(GNL_PATH)get_next_line.a

FILES_PATH		=	src

SRCS			=	$(addprefix $(FILES_PATH)/, $(addsuffix .c, $(FILES)))
BONUS_SRCS		=	$(addprefix $(FILES_PATH)/, $(addsuffix .c, $(BONUS_FILES)))

OBJS			=	$(SRCS:.c=.o)
BONUS_OBJS		=	$(BONUS_SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	@$(AR) $@ $^
	@echo "$(GREEN)-== $(NAME) created! ==-$(DEFAULT)"

$(LIBFT):
	@make -s -C $(LIBFT_PATH)

$(GNL):
	@make -s -C $(GNL_PATH)

bonus: $(BONUS_OBJS)
	@$(AR) $(BONUS_NAME) $^
	@echo "$(GREEN)-== $(BONUS_NAME) created! ==-$(DEFAULT)"

all: $(NAME)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "$(YELLOW)-== all created object files deleted! -==$(DEFAULT)"

fclean: clean libclean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@echo "$(RED)-== all created files deleted! -==$(DEFAULT)"

libclean:
	@make -s -C $(LIBFT_PATH) fclean
	@make -s -C $(GNL_PATH) fclean
	@echo "$(BLUE)-== all created files deleted in libraries! -==$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re bonus

# ANSI COLOR CODES
DEFAULT = \033[0m
RED = \033[1;31m
YELLOW = \033[1;33m
GREEN = \033[1;32m
BLUE = \033[1;36m