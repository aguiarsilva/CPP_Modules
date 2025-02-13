# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 22:28:45 by baguiar-          #+#    #+#              #
#    Updated: 2025/02/12 22:28:45 by baguiar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

CC = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp \
	  newZombie.cpp \
	  randomChump.cpp \
	  Zombie.cpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %..cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

valgrind: $(NAME)
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re valgrind