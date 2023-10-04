# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 15:07:40 by mkirkgoz          #+#    #+#              #
#    Updated: 2023/10/03 22:12:43 by mkirkgoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
NAME_BONUS = checker.a

SRCS = \
    push_swap.c utils.c valid_checker.c lst_functions.c libft_functions.c split_function.c sort_a.c sort_b.c sort_both.c sort.c \
    three_sorter.c check_first_and_last.c calculate_push_methods.c pushing_b_to_a.c  make_free.c init_list.c\

SRCS_BONUS = \
    checker.c valid_checker.c lst_functions.c utils.c sort_a.c sort_b.c sort_both.c \
	init_list.c node_utils.c make_free.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -rf

PUSH_SWAP = push_swap

CHECKER = checker

all: $(PUSH_SWAP) $(CHECKER)
	@echo "✅"

$(LIBFT):
	$(MAKE) -C ./libft

$(PUSH_SWAP): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(PUSH_SWAP)

$(CHECKER): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(CHECKER)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(PUSH_SWAP)
	$(RM) $(CHECKER)
	@echo "🗑️"

re: fclean all

.PHONY: clean fclean all re
