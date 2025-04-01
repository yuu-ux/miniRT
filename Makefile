# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yehara <yehara@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 19:41:00 by yehara            #+#    #+#              #
#    Updated: 2025/04/01 20:09:36 by yehara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
LIBFT_DIR = ./libft
LIBFT = libft.a
OBJ_DIR = ./obj
SRC_DIR = ./src
CC	= cc
CFLAGS = -g -Wall -Wextra -Werror -I./include -I$(LIBFT_DIR)/include
SRCS = $(SRC_DIR)/main.c \
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT_DIR)/$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re $(LIBFT)
