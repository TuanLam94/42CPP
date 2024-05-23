NAME = ex01

CC = c++ -std=c++98

CFLAGS = -Wall -Werror -Wextra

SRC = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		
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