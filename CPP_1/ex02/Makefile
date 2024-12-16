CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = BRAIN
SRC = main.cpp
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

re : fclean $(NAME)

.PHONY: all clean