# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/17 12:00:44 by aleung-c          #+#    #+#              #
#    Updated: 2015/06/21 19:23:58 by aleung-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SRC = main.cpp AEntity.cpp Projectile.cpp \
Ennemy.cpp Player.cpp Game.cpp GameEvents.cpp Eprojectile.cpp Background.cpp

OBJ = $(SRC:.cpp=.o)

CC = clang++ -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@ -lncurses

%.o: %.cpp
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re