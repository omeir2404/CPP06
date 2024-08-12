NAME    = serialize

CC = c++ -Wall -Werror -Wextra -std=c++98

SRC     = Serialization.cpp main.cpp


all:    $(NAME)

$(NAME):
		$(CC) $(SRC) -o $(NAME)

clean:
		rm -f $(OBJ)

run:	$(NAME)
		./$(NAME)

fclean:	clean
		rm -f $(NAME)

re:		fclean $(NAME)
