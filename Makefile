LIBPATH = libft

LIB = $(LIBPATH)/libft.a

NAME = wolf3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -L libft -lft -L/usr/local/lib -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

SRC =

OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(LIB):
	make -C $(LIBPATH)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBPATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBPATH)

re: fclean all
