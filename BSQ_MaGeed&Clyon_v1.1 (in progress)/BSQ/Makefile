# Program name
NAME = bsq

# Source files
SRC = src/main.c src/map_parser.c src/solver.c src/printer.c \
      src/utils.c src/utils_2.c src/utils_3.c src/utils_4.c

# Object files
OBJS = $(SRC:.c=.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include

# Norminette rule
NORM = norminette

# Build rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rules
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Norminette check
norm:
	$(NORM) $(SRC) include/bsq.h

# Phony targets
.PHONY: all clean fclean re norm