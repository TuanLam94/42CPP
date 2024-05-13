NAME = megaphone

CC = c++ -std=c++98

CFLAGS = -Wall -Wextra -Werror

SRC = megaphone.cpp

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
