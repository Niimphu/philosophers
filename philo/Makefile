CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBS = -lpthread

SRC = src/main.c \
	src/parser.c \
	src/init.c \
	src/create_threads.c \
	src/philo_ready.c \
	src/philosophers.c \
	src/time.c \
	src/utils.c

OBJ = $(SRC:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LIBS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re