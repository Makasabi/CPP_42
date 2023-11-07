# COLORS #

_END			=	\033[0m
_GREYER			=	\033[2m
_BOLD			=	\033[1m
_UNDER			=	\033[4m
_REV			=	\033[7m

_RED			=	\033[31m
_FOREST_GREEN	=	\033[32m
_DARK_BLUE		=	\033[34m
_YELLOW			=	\033[33m
_ORANGE			=	\033[38;5;208m
_PURPLE			=	\033[38;5;129m
_PINK			=	\033[38;5;218m
_CYAN			=	\033[36m
_GREY			=	\033[30m
_BROWN			=	\033[38;5;137m
_KAKI			=	\033[38;5;136m
_GOLD			=	\033[38;5;220m
_SILVER			=	\033[38;6;7m
_MAGENTA		=	\033[35;5m
_EMMERALD		=	\033[38;5;118m
_LILAC			=	\033[38;5;127m
_LAGOON			=	\033[38;5;120m
_AQUAMARINE		=	\033[38;5;122m
_CORAL			=	\033[38;5;201m
_RIVIERA		=	\033[38;5;32m
_SALMON			=	\033[38;5;209m
 
 # MAKEFILE #

NAME 			=	megaphone

SRC				=	megaphone.cpp

CC				=	g++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98

OBJ				=	$(SRC:.cpp=.o)

%.o:%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(_ORANGE)Compiling..."

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(_YELLOW)Usage : ./$(NAME)$(_GREYER) $(_BOLD)[\"Optionnal string to uppercase\"]$(_END)"

all: $(NAME)

clean:
	@rm $(OBJ)
	@echo "$(_ORANGE)Cleaning"

fclean:clean
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
