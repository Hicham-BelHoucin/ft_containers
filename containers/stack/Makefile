# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 10:49:47 by hbel-hou          #+#    #+#              #
#    Updated: 2022/09/21 10:52:03 by hbel-hou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Stack

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Stack.cpp 
		
SRCOBJ = $(SRCS:.cpp=.o)

INCLUDE = Stack.hpp

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