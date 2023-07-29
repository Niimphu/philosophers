define SPAGHETTI

\033[37m▒▒▓▓                                                  ░░      ░░░░  ░░░░      ░░░░

                              ██              ██
                            ██              ██
                          ██        ██    ██
                          ██      ██      ██
                            ██    ██        ██
            ░░░░              ▒▒  ██          ▒▒  ░░
                              ██    ██        ██
                            ██        ██    ██
                                      ██  ██
                                    ██
                                                  ░░\033[0m
\033[33m                  ██████        ████████████\033[0m
\033[33m                ██      ██    ██            ██\033[0m
\033[33m              ██    ████  ████    ████████    ██              ████\033[0m
\033[33m            ██    ██    ████    ██        ██    ██████      ██    ██\033[0m        \033[39m    _____                              _\033[0m
\033[33m            ██  ██  ██████    ██    ████    ██    ██  ██  ██        ██\033[0m      \033[39m   /  ___|                            | |\033[0m
\033[33m          ██  ▓▓  ██  ██    ██    ██    ██    ██    ▓▓  ▓▓          ██\033[0m      \033[39m   \ `--. _ __   __ _  __ _ _   _  ___| |_ ___ _   _\033[0m
\033[31m          ████████████████████████████████████████████████████    ██\033[0m        \033[39m    `--. \ '_ \ / _` |/ _` | | | |/ _ \ __/ _ \ | | |\033[0m
\033[31m            ██████████████████████████████████████      ████    ██\033[0m          \033[39m   /\__/ / |_) | (_| | (_| | |_| |  __/ ||  __/ |_| |\033[0m
\033[31m            ██████████████████████████████████████      ████  ██\033[0m            \033[39m   \____/| .__/ \__,_|\__, |\__,_|\___|\__\___|\__, |\033[0m
\033[31m              ██████████████████████▓▓██████████      ████    ██\033[0m            \033[39m         | |           __/ |                    __/ |\033[0m
\033[31m                ██████████████████████████████    ██████        ██\033[0m          \033[39m         |_|          |___/                    |___/\033[0m
\033[31m                  ████████████████████████████████████\033[0m

endef

export SPAGHETTI

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

LIBS = -lpthread

SRC_DIR = src

OBJ_DIR = build

SRC = main.c \
	init.c \
	create_threads.c \
	philo_ready.c \
	philosophers.c \
	waiters.c \
	life_actions.c \
	time.c \
	utils.c \
	checkers.c \
	terminate.c \
	free.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

FUN_SRC := $(filter-out utils.c, $(SRC)) utils_fun.c spaghetti.c

FUN_OBJ := $(addprefix $(OBJ_DIR)/, $(FUN_SRC:.c=.o))

NAME = philo

all: $(NAME)

$(NAME): $(OBJ)
	clear
	@echo "$$SPAGHETTI"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f build/*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

fun: $(FUN_OBJ)
	clear
	@echo "$$SPAGHETTI"
	@$(CC) $(CFLAGS) $(FUN_OBJ) -o $(NAME) $(LIBS)

refun: fclean fun

.PHONY: all clean fclean re