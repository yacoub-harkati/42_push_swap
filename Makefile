CC = cc
CFLAGS= -Wall -Wextra -Werror -fsanitize=address -g3
NAME = push_swap
SRCS= $(wildcard *.c)
OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re