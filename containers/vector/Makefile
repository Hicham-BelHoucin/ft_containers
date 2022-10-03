# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 10:51:18 by hbel-hou          #+#    #+#              #
#    Updated: 2022/10/02 18:24:01 by hbel-hou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Vector

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS = Vector.cpp

SRCOBJ = $(SRCS:.cpp=.o)

INCLUDE = Vector.hpp

all: $(NAME)

$(NAME) : $(INCLUDE) $(SRCOBJ)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

%.o : %.cpp $(INCLUDE)
	$(CC) $(CFLAGS) -o $@  -c $<

clean:
	@rm -f $(SRCOBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all