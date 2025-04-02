# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 19:41:00 by yehara            #+#    #+#              #
#    Updated: 2025/04/02 22:52:07 by ssoeno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
LIBFT_DIR = ./libft
LIBFT = libft.a
MLX_DIR = minilibx-linux
OBJ_DIR = ./obj
SRC_DIR = ./src
CC	= cc
CFLAGS = -g -Wall -Wextra -Werror -I./include -I$(LIBFT_DIR)/include -I$(MLX_DIR)
LFLAGS = -g -Wall -Wextra -Werror -L$(MLX_DIR) -lmlx  -L$(LIBFT_DIR) -lft -lXext -lX11 -lm -lbsd
MLX_NAME = libmlx_Linux.a
MLX = $(MLX_DIR)/$(MLX_NAME)
SRCS = $(SRC_DIR)/main.c
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(LIBFT_DIR)/$(LIBFT) $(MLX) $(OBJS)
	$(CC) $^ $(LFLAGS) -o $@

$(LIBFT_DIR)/$(LIBFT):
	git submodule update --init --remote
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

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
