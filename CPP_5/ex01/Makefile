CXX = g++
CXXFLAG = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = maggots

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAG) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re