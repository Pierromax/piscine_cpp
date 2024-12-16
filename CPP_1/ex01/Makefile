CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = zombieHorde
SRC = main.cpp \
		Zombie.cpp \
		zombieHorde.cpp\

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)

.PHONY: all clean