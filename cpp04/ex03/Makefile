NAME = ex03

CC = c++ -std=c++98

CFLAGS = -Wall -Werror -Wextra

SRC = main.cpp \
		AMateria.cpp \
		Character.cpp \
		ICharacter.cpp \
		Ice.cpp \
		Cure.cpp \
		IMateriaSource.cpp \
		MateriaSource.cpp \
		
		
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