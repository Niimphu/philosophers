define SPAGHETTI

                                                                                  
▒▒▓▓                                                  ░░      ░░░░  ░░░░      ░░░░
                                                                                  
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
                                                  ░░                              
                  ██████        ████████████                                      
                ██      ██    ██            ██                                    
              ██    ████  ████    ████████    ██              ████                
            ██    ██    ████    ██        ██    ██████      ██    ██              
            ██  ██  ██████    ██    ████    ██    ██  ██  ██        ██            
          ██  ▓▓  ██  ██    ██    ██    ██    ██    ▓▓  ▓▓          ██            
          ████████████████████████████████████████████████████    ██              
            ██████████████████████████████████████      ████    ██                
            ██████████████████████████████████████      ████  ██                  
              ██████████████████████▓▓██████████      ████    ██                  
                ██████████████████████████████    ██████        ██                
                  ██████████████████████████  ████████                            
                      ██████████████▓▓████████▓▓▓▓                                
                                                                                  
                                                                                  
                            \033[0;31mMMM.... SPAGUETY\033[0m

endef

export SPAGHETTI

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

LIBS = -lpthread

SRC_DIR = src

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

OBJ_DIR = build

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

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
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re