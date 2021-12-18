# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 13:36:04 by mel-amma          #+#    #+#              #
#    Updated: 2021/12/17 15:25:37 by mel-amma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c get_next_line_utils.c helpers.c  keys.c main.c parser.c pointmanipulation.c screen.c split.c writers.c initializeandclear.c fdf.c
CC = gcc
NAME = fdf
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit


all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)


clean :
	$(RM) $(NAME) 
	
fclean : clean
	$(RM) $(NAME)

re: fclean all
	
.PHONY : all clean fclean re
