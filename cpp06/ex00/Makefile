CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

EXEC = scalarconverter

SRCS = \
		main.cpp \
		ScalarConverter.cpp \

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