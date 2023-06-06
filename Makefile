NAME = push_swap

LIB_DIR = libft
SRC_DIR = src
VPATH = src:libft

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_DIR = obj

INCLUDES = -Ilibft/includes -Iincludes
CFLAGS = -Wall -Wextra -Werror -MMD

SRC = main.c

DEP = $(OBJ:.o=.d)

####
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR)
	@cc $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIB_DIR) -lft

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@cc $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(DEP)

clean:
	@make clean -C $(LIB_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIB_DIR)
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
re: fclean all