# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 19:41:00 by yehara            #+#    #+#              #
#    Updated: 2025/04/05 19:39:55 by yehara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = parse
CC	= cc
CFLAGS = -g -Wall -Wextra -Werror -I../../include -I../../libft/include
SRCDIR  = ../../src/parse
SRCS = main.c \
	$(SRCDIR)/parse_ambient.c \
	$(SRCDIR)/parse_util.c \
	$(SRCDIR)/parse.c \
	$(SRCDIR)/parse_camera.c \
	$(SRCDIR)/parse_light.c \
	../../src/util/error.c \
	../../src/raytracing/vector_utils.c
OBJ = $(notdir $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ ../../libft/libft.a -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
