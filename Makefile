# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yehara <yehara@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 19:41:00 by yehara            #+#    #+#              #
#    Updated: 2025/04/02 21:13:18 by yehara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

# parse
PARSE_SRCS = parse.c \
			 parse_ambient.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# srcs
SRCS = $(SRC_DIR)/main.c \
	   $(addprefix $(SRC_DIR)/parse/, $(PARSE_SRCS))

# libft
LIBFT_DIR = ./libft
LIBFT = libft.a

# mlx
MLX_DIR = ./minilibx-linux
MLX = libmlx_Linux.a

OBJ_DIR = ./obj
SRC_DIR = ./src

# cc
CC	= cc
CFLAGS = -g -Wall -Wextra -Werror -I./include -I$(LIBFT_DIR)/include -I$(MLX_DIR)
LFLAGS = -g -Wall -Wextra -Werror -L$(MLX_DIR) -lmlx  -L$(LIBFT_DIR) -lft -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX) $(OBJS)
	@$(CC) $^ $(LFLAGS) -o $@

$(LIBFT_DIR)/$(LIBFT):
	@git submodule update --init --remote
	@make -s -C $(LIBFT_DIR)

$(MLX_DIR)/$(MLX):
	@make -C $(MLX_DIR) > /dev/null 2>&1

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re $(LIBFT)
