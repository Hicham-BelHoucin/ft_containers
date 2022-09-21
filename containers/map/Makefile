# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 10:26:43 by hbel-hou          #+#    #+#              #
#    Updated: 2022/09/21 10:38:04 by hbel-hou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Map

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = map.cpp 
		
SRCOBJ = $(SRCS:.cpp=.o)

INCLUDE = map.hpp

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