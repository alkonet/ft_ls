# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gloggins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 12:57:12 by gloggins          #+#    #+#              #
#    Updated: 2020/03/03 12:57:12 by gloggins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# For still making moves if diles have the name

.PHONY: all, $(NAME), clean, fclean, re

# Colors

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

NAME = ft_ls

CC = gcc

INCLUDES = -I ./includes -I ./libft/includes

LIBFT = libft/libft.a

SRCS = ./src/ft_ls.c \
	./src/counter.c \
	./src/direct.c \
	./src/utilities.c \
	./src/arguments.c \
	./src/errors.c \
	./src/ft_print.c \
	./src/memory_free.c \
	./src/reader_output.c \
	./src/sorting.c \
	./src/options.c \
	./src/fill.c

OPTIONS = -Wall -Wextra -Werror

DEBUGFLAG = -g3

RM = rm -rf

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(SRCS) $(INCLUDES) $(LIBFT) -o $(NAME) $(OPTIONS)
	@echo "$(GREEN)LS is ready to use$(RESET)"

clean:
	@make -C libft fclean
	@echo "$(YELLOW)Cleaning the libft$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)LS removing$(RESET)"

re: fclean all

