# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 12:56:45 by skuhlcke          #+#    #+#              #
#    Updated: 2025/05/20 16:57:52 by skuhlcke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft -g

SRC = src/ft_strol.c \
      src/p_ops.c \
      src/push_swap_algorithm.c \
      src/push_swap_utils.c \
      src/push_swap.c \
      src/r_ops.c \
      src/radix_sort.c \
      src/rr_ops.c \
      src/s_ops.c \
      src/stack_creator.c \
	  src/stack_utils.c \
	  src/filter_the_stack.c \
	  src/filter_utils.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
