NAME = phonebook

CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp contact.cpp helpers.cpp phonebook.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)	