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

SRC = src/main.c \
	src/init.c \
	src/create_threads.c \
	src/philo_ready.c \
	src/philosophers.c \
	src/waiters.c \
	src/life_actions.c \
	src/time.c \
	src/utils.c \
	src/checkers.c \
	src/terminate.c \
	src/free.c

OBJ = $(SRC:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJ)
	clear
	@echo "$$SPAGHETTI"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re