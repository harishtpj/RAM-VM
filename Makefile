SRC_FILES = vm.c
CFLAGS = -Wall -Wextra
INC = includes
CC = gcc
NAME = ram-vm

all: build

build:
	@$(CC) $(CFLAGS) -I $(INC) $(SRC_FILES) -o $(NAME)
	@echo "---> Built RAM-VM"

run: build
	@echo "---> Running RAM-VM"
	@./$(NAME) $(ARGS)

clean:
	@rm $(NAME)
	@echo "---> Cleaned Working Directory"