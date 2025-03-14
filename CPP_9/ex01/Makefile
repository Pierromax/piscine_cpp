CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -g3 -std=c++98

OBJS_DIR = .obj
SRCS = main.cpp RPN.cpp
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
NAME = RPN

all : $(NAME)

$(OBJS_DIR)/%.o : %.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean :
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

