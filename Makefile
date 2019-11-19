##
## EPITECH PROJECT, 2018
## Ndr's Makefile
## File description:
## Makefile for C Epitech Projects
##

## Program name
EXEC=my_rpg
DEBUG_MODE=yes
# Source files
SRC=$(shell find src -name "*.c")

## Compiler
CC=gcc
# Normal compilation flags
CFLAGS=-I$(INC_DIR)
# Additional debug flags
DEBUG_FLAGS=-g -W -Wall -Wextra -Wshadow
# Linking flags
LDFLAGS=-L$(LIB_DIR) -l$(LIB) -lc_graph_prog
OBJ=$(SRC:.c=.o)

# Includes directory
INC_DIR=$(realpath ./include)
# Library directory and name
LIB_DIR=$(realpath ./lib/my)
LIB=my

	##		##		##
##	PLEASE DO NOT MODIFY ANYTHING BELOW	##
	##		##		##

.PHONY: clean fclean debug relib

all: $(EXEC)

# Linking of object files
$(EXEC): lib/my/libmy.a $(OBJ)
ifeq ($(DEBUG_MODE),yes)
	@printf "<>\t\e[34mLinking $(EXEC) in debug mode !\e[0m\n"
else
	@printf "<>\t\e[34mLinking $(EXEC)...\e[0m\n"
endif
	$(CC) -o $(EXEC) $(OBJ) $(LDFLAGS)

# Toggles debug mode
debug: fclean
ifeq ($(DEBUG_MODE),no)
	@printf "<>\t\e[32mDebug mode enabled\e[0m\n"
	@sed -i '0,/DEBUG_MODE=no/{s/DEBUG_MODE=no/DEBUG_MODE=yes/}' Makefile
else
	@printf "<>\t\e[31mDebug mode disabled\e[0m\n"
	@sed -i '0,/DEBUG_MODE=yes/{s/DEBUG_MODE=yes/DEBUG_MODE=no/}' Makefile
endif

#Compiles source files to object files
%.o: %.c
ifeq ($(DEBUG_MODE),no)
	$(CC) -c $< -o $@ $(CFLAGS)
else
	$(CC) -c $< -o $@ $(CFLAGS) $(DEBUG_FLAGS)
endif

clean:
	@printf "<>\t\e[31mDeleting object and temporary files...\e[0m\n"
	@find -name "*~" -delete -o -name "#*#" -delete -o -name "*.o" -delete

fclean: clean
	@printf "<>\t\e[31mDeleting $(EXEC) binary...\e[0m\n"
	@-rm $(EXEC) tools/a.out

# Rebuilds project
re: fclean all

# Builds libmy if necessary
lib/my/libmy.a:
	@printf "<>\t\e[33mCalling library Makefile...\e[0m\n"
	make -C $(LIB_DIR)

# Rebuilds libmy
relib:
	@printf "<>\t\e[33mCalling library Makefile (target \"re\")...\e[0m\n"
	make -C $(LIB_DIR) re
