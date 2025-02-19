# Variables
C = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = materia

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(C) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(C) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re