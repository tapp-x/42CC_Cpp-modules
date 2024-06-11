CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRCS = \
		main.cpp \
		BitcoinExchange.cpp \

OBJS = $(SRCS:.cpp=.o)

EXEC = btc

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re