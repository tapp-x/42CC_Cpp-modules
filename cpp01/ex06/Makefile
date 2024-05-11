# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 09:31:57 by tappourc          #+#    #+#              #
#    Updated: 2024/05/10 17:21:16 by tappourc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

EXEC = harlFilter

SRCS = \
		main.cpp \
		Harl.cpp \

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
