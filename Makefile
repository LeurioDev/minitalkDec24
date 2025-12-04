NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
HEADER = minitalk.h
SRCS = srcs/func_aux.c
SRCS_CLIENT = srcs/client.c
SRCS_SERVER = srcs/server.c
SERVER = server
CLIENT = client

all: $(NAME)
	@echo "\033[32mAll done\033[0m"

$(NAME): $(SRCS) $(HEADER) $(SERVER) $(CLIENT)
	@echo "\033[33mCompiling\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

$(SERVER): $(SRCS_SERVER) $(HEADER)
	@echo "\033[33mCompiling\033[0m"
	@$(CC) $(CFLAGS) -o $(SERVER) $(SRCS_SERVER) $(SRCS)

$(CLIENT): $(SRCS_CLIENT) $(HEADER)
	@echo "\033[33mCompiling\033[0m"
	@$(CC) $(CFLAGS) -o $(CLIENT) $(SRCS_CLIENT) $(SRCS)