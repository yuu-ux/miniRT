# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 13:31:55 by yehara            #+#    #+#              #
#    Updated: 2025/04/04 21:30:35 by yehara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g
FLAGS			=	-Iinclude
MAKEFLAGS		+=	--no-print-directory

NAME			=	libft.a
PRINTFA			=	./ft_printf/printf.a


SRC_DIR			=	./srcs
SRC_FILES		= 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
					ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
					ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_bzero.c ft_atoi.c ft_calloc.c \
					ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c ft_chomp.c ft_chop.c \
					ft_xmalloc.c ft_realloc.c free_strjoin.c ft_atol.c ft_isspace.c ft_isvalue.c ft_xopen.c ft_xclose.c \
					ft_atof.c ft_xsplit.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c  \
					ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRC_BONUS_FILES	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
						ft_lstclear.c ft_lstiter.c ft_lstmap.c

ifeq ($(BFLAGS), bonus)
TARGET_SRC		=	$(SRC_FILES) $(SRC_BONUS_FILES)
else
TARGET_SRC		=	$(SRC_FILES)
endif

OBJ_DIR			=	./objs
OBJ_FILES		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(TARGET_SRC))

DEPENDENCY		=	$(patsubst %.c, $(OBJ_DIR)/%.d, $(TARGET_SRC))


all: $(NAME)

$(NAME): $(OBJ_FILES)
	@make -C ft_printf
	@cp $(PRINTFA) $@
	$(AR) rcs $@ $^

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(FLAGS) -MMD -MP -c $< -o $@

-include $(DEPENDENCY)

bonus:
	@$(MAKE) all BFLAGS=bonus

clean:
	@make -C ft_printf clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C ft_printf fclean
	rm -f $(NAME)

re: fclean all

.DEFAULT_GOAL	:=	all

.PHONY : all clean fclean re
