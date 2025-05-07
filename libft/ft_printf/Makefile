# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 16:35:15 by yehara            #+#    #+#              #
#    Updated: 2024/10/02 19:39:19 by ebarayuug        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= printf.a
CC	= cc
FLAGS	= -Wall -Werror -Wextra
SRCS	= ft_printf.c ft_printf_char.c ft_printf_dec.c ft_printf_hex.c ft_printf_ptr.c ft_printf_str.c ft_printf_unsigned_dec.c utils.c ft_itoa.c
OBJS	= ${SRCS:.c=.o}

%.o:%.c
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${AR} rc ${NAME} ${OBJS}

all: ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

norm :
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine *.h

.PHONY: all re clean fclean
