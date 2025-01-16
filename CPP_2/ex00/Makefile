# Variables
CC = g++
CFLAGS = -Wall -Wextra -std=c++98
SRC = main.cpp Fixed.cpp
OBJ = $(SRC:.cpp=.o)
NAME = fixed

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean re fclean