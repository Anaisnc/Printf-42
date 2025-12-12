
SRC = ft_printf.c \
	utils.c \

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

DEP = $(OBJ:.o=.d)

NAME = printf.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
