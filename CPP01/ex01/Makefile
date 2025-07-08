# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 14:41:15 by baguiar-          #+#    #+#              #
#    Updated: 2025/02/21 14:41:15 by baguiar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = horde

CC = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/

SRC = main.cpp \
	  zombieHorde.cpp \
	  Zombie.cpp \

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

INC = -I $(INC_DIR)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(CPPFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

valgrind: $(NAME)
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re valgrind