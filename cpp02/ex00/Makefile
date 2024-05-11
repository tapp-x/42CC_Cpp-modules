# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/11 13:29:26 by tappourc          #+#    #+#              #
#    Updated: 2024/05/11 15:51:44 by tappourc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

EXEC = fixed

SRCS = \
		main.cpp \
		Fixed.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

fclean: clean
	rm -f $(EXEC)

clean:
	rm -f $(OBJS)

re: fclean all
