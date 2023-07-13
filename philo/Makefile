NAME 		= philo

S			= src/
O			= obj/

OBJ			= $(SRC:$S%=$O%.o)

INCLUDES = -Iinc
CFLAGS = -Wall -Wextra -Werror -O3 -pthread #-g -fsanitize=thread -static-libsan

SRC = \
$S/main.c		$S/mutex.c			$S/errors.c			$S/utils.c		$S/philo.c		\
$S/governor.c	$S/philo_actions.c	$S/philo_utils.c	$S/attr.c		$S/printing.c

####

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

$O:
	@mkdir $@

$(OBJ): | $O

$(OBJ): $O%.o: $S%
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $O

fclean: clean
	rm -f $(NAME)

re: fclean all
