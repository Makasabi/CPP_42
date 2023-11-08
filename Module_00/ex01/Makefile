# COLORS #

_END			=	\033[0m
_GREYER			=	\033[2m

_RED			=	\033[31m
_YELLOW			=	\033[33m
_ORANGE			=	\033[38;5;208m
 
 # MAKEFILE #

NAME 			=	phonebook

SRC				=	main.cpp \
					PhoneBook.cpp \
					utils.cpp \
					Contact.cpp \

CC				=	g++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98

OBJ				=	$(SRC:.cpp=.o)

%.o:%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(_ORANGE)Compiling:" $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(_YELLOW)Usage : ./$(NAME)$(_END)"

all: $(NAME)

clean:
	@rm $(OBJ)
	@echo "$(_RED)Cleaning"

fclean:clean
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
