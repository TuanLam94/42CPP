NAME = horde

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = Zombie.cpp \
		zombieHorde.cpp \
		main.cpp \

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