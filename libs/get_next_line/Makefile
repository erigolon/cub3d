# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigolon <erigolon@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 14:05:02 by erigolon          #+#    #+#              #
#    Updated: 2024/11/15 12:08:43 by erigolon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

LIB = ar rcs

SRC = get_next_line.c \
	get_next_line_utils.c

OBJ = ${SRC:.c=.o}

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	@$(LIB) $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re