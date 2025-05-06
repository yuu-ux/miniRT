# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 19:41:00 by yehara            #+#    #+#              #
#    Updated: 2025/05/06 15:24:04 by yehara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

# parse
PARSE_SRCS = parse.c \
			 parse_ambient.c \
			 parse_util.c \
			 parse_camera.c \
			 parse_light.c \
			 parse_sphere.c \
			 parse_plane.c \
			 parse_cylinder.c

# raytracing
RAYTRACING_SRCS = raytracing.c \
				  vector_utils.c \
				  vector_products.c \
				  setup_camera.c \
				  hit_object.c \
				  render_utils.c \
				  compute_phong.c \
				  get_normal.c \
				  hit_cylinder.c
# util
UTIL_SRCS = error.c \
			ft_xatof.c \
			split_space.c
# init
INIT_SRCS = init.c

# event
EVENT_SRCS = event.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# srcs
SRCS = $(SRC_DIR)/main.c \
	   $(addprefix $(SRC_DIR)/parse/, $(PARSE_SRCS)) \
	   $(addprefix $(SRC_DIR)/util/, $(UTIL_SRCS)) \
	   $(addprefix $(SRC_DIR)/raytracing/, $(RAYTRACING_SRCS)) \
	   $(addprefix $(SRC_DIR)/init/, $(INIT_SRCS)) \
	   $(addprefix $(SRC_DIR)/event/, $(EVENT_SRCS))

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
