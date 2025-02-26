CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

OBJS_DIR = .obj
SRCS = main.cpp
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
NAME = btc

all : $(NAME)

$(OBJS_DIR)/%.o : %.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

