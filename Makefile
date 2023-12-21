CC = cc
CFLAGS= -Wall -Wextra -Werror
NAME = push_swap
BONUS_NAME = checker
SRCS= algorithm_utils.c algorithm.c error_check.c error_free.c finders.c ft_atol.c ft_split.c init_stack.c is_stack_sorted.c \
	libft_utils.c libft_utils_2.c lst_utils.c push_commands.c push_swap.c push_swap_utils.c \
	rotate_commands.c small_sort.c swap_commands.c reverse_rotate_commands.c setters.c 
SRCS_BONUS= algorithm_utils.c algorithm.c error_check.c error_free.c finders.c ft_atol.c ft_split.c init_stack.c is_stack_sorted.c \
	libft_utils.c libft_utils_2.c lst_utils.c push_commands.c checker_bonus.c push_swap_utils.c \
	rotate_commands.c small_sort.c swap_commands.c reverse_rotate_commands.c setters.c  gnl.c checker_utils.c
OBJS= $(SRCS:.c=.o)
OBJS_BONUS= $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME)

clean: 
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	
re: fclean all

.PHONY: all clean fclean re