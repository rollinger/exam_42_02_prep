NAME=exam

$(NAME):
	gcc *.c -o $(NAME)

all: $(NAME)

clean:
	rm -rf *.o *.gch

fclean: clean
	rm -rf $(NAME)

re: fclean all