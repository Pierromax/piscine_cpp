CC := c++
CFLAG := -Wall -Wextra -Werror -std=c++98

NAME := polymorph
SRC := Animal.cpp Dog.cpp Cat.cpp Main.cpp WrongAnimal.cpp WrongCat.cpp

OBJ := $(SRC:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
