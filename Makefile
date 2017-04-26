
NAME = vm

FILES = fill  vm_init vm debug
SRC = $(addsuffix .c, $(FILES))
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(HEAD)
HEAD = -I./includes
LIB = ./libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB)
	@echo "Objects Files created."
	@$(CC) -o $(NAME) $(OBJ) -L$(LIB) -lft
	@echo $(NAME) "created."

clean:
	@make clean -C $(LIB)
	@/bin/rm -f $(OBJ)
	@echo "Objects Files removed"

fclean: clean
	@make fclean -C $(LIB)
	@/bin/rm -f $(NAME)
	@echo $(NAME) "removed"

re: fclean all
