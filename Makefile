CC = cc
CFLAGS= -Wall -Wextra -Werror
NAME = push_swap
SRCS= push_swap.c push_swap_utils.c libft_utils.c libft_utils_2.c
OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re