# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 19:41:00 by yehara            #+#    #+#              #
#    Updated: 2025/04/03 19:11:02 by ssoeno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = raytracing
CC	= cc
CFLAGS = -g -Wall -Wextra -Werror -I../../include
SRCDIR  = ../../src/raytracing
SRCS = test.c \
	$(SRCDIR)/vector_products.c \
	$(SRCDIR)/vector_utils.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
