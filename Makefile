# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daalexan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 16:17:48 by daalexan          #+#    #+#              #
#    Updated: 2018/07/25 16:20:22 by daalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = daalexan.filler

HEADER = ./include/libft/
FILL_HEADER = ./include/

SRC = src

CFLAGS = -Wall -Werror -Wextra

CC = gcc

LIB_FILES = ./include/libft/
FILLER_FILES =  src/ft_start.c \
				src/ft_setinfo.c
				
OBJ = $(FILLER_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB_FILES)libft.a
	$(CC) -o $(NAME) $(OBJ) $(LIB_FILES)*.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER) -I $(FILL_HEADER)

$(LIB_FILES)libft.a:
	make -C $(LIB_FILES)
clean:
	make clean -C $(LIB_FILES)
	rm -f $(OBJ)
fclean: clean
	make fclean -C $(LIB_FILES)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
