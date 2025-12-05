NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
HEADER = minitalk.h
SRCS = srcs/func_aux.c srcs/set_of_functions.c
SRCS_CLIENT = srcs/client.c
SRCS_SERVER = srcs/server.c
SERVER = server
CLIENT = client
OBJ = srcs/$(SRCS:.c=.o)

all: $(SERVER) $(CLIENT)
	@echo "\033[32mAll done\033[0m"

$(NAME): all

$(SERVER): $(SRCS_SERVER) $(HEADER)
	@echo "\033[33mCompiling\033[0m"
	@$(CC) $(CFLAGS) -o $(SERVER) $(SRCS_SERVER) $(OBJ)

$(CLIENT): $(SRCS_CLIENT) $(HEADER)
	@echo "\033[33mCompiling\033[0m"
	@$(CC) $(CFLAGS) -o $(CLIENT) $(SRCS_CLIENT) $(OBJ)

clean:
	@echo "\033[33mCleaning\033[0m"
	@$(RM) $(OBJ)

fclean:
	@echo "\033[33mCleaning\033[0m"
	@$(RM) $(OBJ)
	@$(RM) $(SERVER)
	@$(RM) $(CLIENT)

re: fclean all

.PHONY: all clean
