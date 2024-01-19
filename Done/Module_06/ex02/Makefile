# COLORS #

_END			=	\033[0m
_GREYER			=	\033[2m

_RED			=	\033[31m
_YELLOW			=	\033[33m
_ORANGE			=	\033[38;5;208m

# MAKEFILE #

NAME 			=	typeID

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98 -MMD -g

SRCS			=	main.cpp \
					
OBJS_PATH		=	./objs
OBJS_NAMES		=	$(SRCS:.cpp=.o)
OBJS			=	$(addprefix $(OBJS_PATH)/, $(OBJS_NAMES))

DEPS			=	${OBJS:.o=.d}

all: $(NAME)

$(OBJS_PATH)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(_ORANGE)Compiling:" $@

$(OBJS_PATH) :
	@mkdir -p $(OBJS_PATH)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(_YELLOW)Usage : ./$(NAME)$(_GREYER)$(_END)"

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(_RED)Cleaning the mess$(_END)"

fclean:clean
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)