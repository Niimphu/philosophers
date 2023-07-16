CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LIBS = -lpthread

SRC = src/main.c \
	src/init.c \
	src/create_threads.c \
	src/philo_ready.c \
	src/philosophers.c \
	src/time.c \
	src/utils.c \
	src/free.c

OBJ = $(SRC:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re