NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		  adaptive_algorithm.c \
		  bench_print_helpers.c \
		  bench_print.c \
		  complex_algorithm.c \
		  disorder.c \
		  flags_validation.c \
		  input_into_stack.c \
		  input_validation1.c \
		  input_validation2.c \
		  medium_algorithm1.c \
		  medium_algorithm2.c \
		  push_functions.c \
		  reverse_functions.c \
		  rotation_functions.c \
		  simple_algorithm.c \
		  stack_operations.c \
		  split.c \
		  swap_functions.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re