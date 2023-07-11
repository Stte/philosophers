NAME = philo

SRC_DIR = ./src
VPATH = src:inc

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_DIR = obj

INCLUDES = -Iinc
CFLAGS = -Wall -Wextra -Werror -MMD -O3 -pthread #-fsanitize=thread -static-libsan

SRC = \
<<<<<<< HEAD:philo/Makefile
main.c			mutex.c			errors.c			utils.c			philo.c		\
governor.c		philo_actions.c	philo_utils.c		attr.c
=======
main.c		mutex.c		errors.c		utils.c		more_utils.c		philos.c \
governor.c	eatsleepdierepeat.c			philos_run.c
>>>>>>> b4a66243474a5c4c6c3d6bd0f0215d7fe83346f3:Makefile

DEP = $(OBJ:.o=.d)

####
all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(DEP)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)
re: fclean all
