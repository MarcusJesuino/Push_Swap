#==========================================#
#                PUSH_SWAP                 #
#==========================================#

NAME = push_swap

#---------------COLORS---------------------#

GREEN	= \\033[0;32m
YELLOW	= \\033[0;33m
BLUE	= \\033[0;34m
RED		= \\033[0;31m
RESET	= \\033[0m

#---------------FLAGS----------------------#

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
DEPFLAGS	= -MMD -MP

RM			= rm -rf
MKDIR		= mkdir -p

#---------------DIRECTORIES----------------#

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

#---------------LIBS-----------------------#

LIBFT_DIR	= lib/libft
LIBFT		= $(LIBFT_DIR)/libft.a

INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR)

#---------------SOURCES--------------------#

SRC =	main.c \
		operations/push.c operations/swap.c operations/rotate.c operations/reverse_rotate.c \
		parse/parse.c parse/parse_utils.c parse/validate.c parse/check_dup.c \
		sort/index.c sort/radix.c sort/small_sort.c sort/small_sort_utils.c \
		stack/stack.c stack/stack_utils.c

SRCS =	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS =	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS =	$(OBJS:.o=.d)

#---------------RULES----------------------#

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo -e "$(BLUE) Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo -e "$(GREEN) ✔ $(NAME) created successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(dir $@)
	@echo -e "$(YELLOW) Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo -e "$(BLUE) Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo -e "$(RED) Cleaning objects...$(RESET)"
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo -e "$(GREEN) ✔ Clean done$(RESET)"

fclean: clean
	@echo -e "$(RED)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo - e "$(GREEN)✔ Full clean done$(RESET)"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re