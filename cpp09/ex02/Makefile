NAME = PmergeMe

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -std=c++98 -g3

SRC = main.cpp \
		PmergeMe.cpp \
		
OBJ = $(SRC:.cpp=.o)

RM = rm -rf

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

valgrind : all
	valgrind --leak-check=full -show-leak-kinds=all --track-origins=yes
