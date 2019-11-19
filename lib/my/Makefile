##
## EPITECH PROJECT, 2018
## Ndr's libmy Makefile
## File description:
## Makefile for libmy
##

## Library name
LIB=libmy.a
SRC=$(wildcard *.c)
# Header file (containing all lib's external functions prototypes)
LIB_HEADERS=my.h
# Destination folder for lib headers
INC_CPY=$(realpath ../../include)

## Compiler
CC=gcc
# Archiver
AR=ar
# Compilation flags
CFLAGS=-I$(INC_DIR)
# Includes for lib sources
INC_DIR=$(realpath .)
OBJ=$(SRC:.c=.o)

	##		##		##
##	PLEASE DO NOT MODIFY ANYTHING BELOW	##
	##		##		##

.PHONY: clean fclean

all: $(LIB)

$(LIB): $(OBJ)
	@printf "<LIB>\t\e[34mCreating $(LIB) archive...\e[0m\n"
	$(AR) rc $(LIB) $(OBJ)
	@printf "<LIB>\t\e[34mCopying $(LIB_HEADERS) in include dir...\e[0m\n"
	@cp $(LIB_HEADERS) $(INC_CPY)

clean:
	@printf "<LIB>\t\e[31mDeleting object and temporary files...\e[0m\n"
	@find -name "*~" -delete -o -name "#*#" -delete -o -name "*.o" -delete

fclean: clean
	@printf "<LIB>\t\e[31mDeleting $(LIB) archive...\e[0m\n"
	@-rm $(LIB)

re: fclean all
