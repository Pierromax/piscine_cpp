# Variables
CC = g++
CFLAGS = -Wall -Wextra -std=c++98
SRC = main.cpp ClapTrap.cpp
OBJ = $(SRC:.cpp=.o)
NAME = claptrap

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean $(NAME)

.PHONY: all clean re fclean
