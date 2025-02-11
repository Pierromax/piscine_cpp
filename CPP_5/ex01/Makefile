# Variables
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++11
SRCS = main.cpp Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = program

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re