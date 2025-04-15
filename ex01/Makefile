CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I.

NAME = iter
SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) iter.hpp
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp iter.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 