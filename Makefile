PROJECT	= ft_containers

### COMPILATION ###
CC		= clang++
AR		= ar rcs
CFLAGS	= -Wall -Wextra -std=c++98
CFLAGS	+= -MMD -MP
INCLUDE	= -I$(H_DIR) -I$(TEST_DIR)
LFLAGS	=
LINKS	=
VFLAGS	=

### EXECUTABLE ###
TEST	= $(OBJ_DIR)/test_bin
NAME	= lib$(PROJECT).a
ARGS	=

### ENV VARIABLES ###
-include .env
FDEBUG		?= false
FEXTRA		?= false
FTEST		?= false
FNOERROR	?= false
FASAN		?= false

ifeq ($(FNOERROR),false)
	CFLAGS += -Werror
endif

ifeq ($(FEXTRA),true)
	CFLAGS	+= -Wshadow -Wpedantic -Wuninitialized -Wmissing-include-dirs -Wundef -Winvalid-pch
	CFLAGS	+= -Winit-self -Wswitch-enum -Wswitch-default -Wformat=2 -Wformat-nonliteral -Wformat-security -Wformat-y2k
	CFLAGS	+= -Wdouble-promotion -Wfloat-equal -Wpointer-arith -Wno-self-assign-overloaded
endif

ifeq ($(FDEBUG),true)
	CFLAGS += -g3
	VFLAGS += -D DEBUG_MODE
endif

ifeq ($(FASAN),true)
	CFLAGS += -fsanitize=address
endif

ifeq (std, $(filter std,$(MAKECMDGOALS)))
	VFLAGS	+= -D MODE_STD
endif

### INCLUDES ###
OBJ_DIR		= bin
SRC_DIR		= src
TEST_DIR	= tests
H_DIR		= incl

### SOURCE FILES ###
SRCS	=	stack.cpp

T_SRCS	=	tests/main.cpp \
			tests/core/Test.cpp \
			tests/core/Config.cpp \
			tests/core/run_tests.cpp \
			tests/stack.cpp \
			tests/vector.cpp \
			tests/pair.cpp \
			tests/reverse_iterator.cpp \

### OBJECTS ###
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS	= $(OBJS:.o=.d)
T_OBJS	= $(addprefix $(OBJ_DIR)/, $(T_SRCS:.cpp=.o))
T_DEPS	= $(T_OBJS:.o=.d)

### COLORS ###
RESET	= \033[0m
BLACK	= \034[1;30m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
PURPLE	= \033[1;35m
CYAN	= \033[1;36m
WHITE	= \033[1;37m

### OTHERS ###
UNAME_S = $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	VALGRIND	= leaks --list --groupByType --atExit --
else
	VALGRIND	= valgrind --track-origins=yes --leak-check=full
endif

### RULES ###
all:	$(NAME)

$(NAME):	$(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(PROJECT): $(BLUE)Creating lib file -> $(WHITE)$(notdir $@)... $(GREEN)[Done]$(RESET)"
	@echo "$(PROJECT): $(GREEN)Project successfully compiled$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) $(VFLAGS) -c $< -o $@
	@echo "$(PROJECT): $(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(GREEN)[Done]$(RESET)"

$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) $(VFLAGS) -c $< -o $@
	@echo "$(PROJECT): $(BLUE)Creating test object file -> $(WHITE)$(notdir $@)... $(GREEN)[Done]$(RESET)"

$(TEST): $(NAME) $(T_OBJS)
	@$(CC) $(CFLAGS) $(LFLAGS) $(T_OBJS) -o $(TEST)
	@echo "$(PROJECT): $(GREEN)Test binary created -> $(WHITE)$@$(RESET)"

run: $(NAME)
	@./$(NAME) $(ARGS)

val: $(NAME)
	@$(VALGRIND) ./$(NAME) $(ARGS)

test: $(TEST)
	@./$(TEST)

std: ;

info:
	@echo "$(BLUE)NAME$(RESET): $(NAME)"
	@echo "$(BLUE)CFLAGS$(RESET): $(CFLAGS)"
	@echo "$(BLUE)INCLUDE$(RESET): $(INCLUDE)"
	@echo "$(BLUE)LFLAGS$(RESET): $(LFLAGS)"
	@echo "$(BLUE)LINKS$(RESET): $(LINKS)"
	@echo "$(BLUE)SRCS$(RESET): $(SRCS)"
	@echo "$(BLUE)T_SRCS$(RESET): $(T_SRCS)"

clean:
	@echo "$(PROJECT): $(RED)Supressing object files$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@echo "$(PROJECT): $(RED)Supressing program file$(RESET)"
	@rm -f $(NAME)

re:	fclean
	@$(MAKE) all

.PHONY:	all clean fclean re

-include $(DEPS)
-include $(T_DEPS)
