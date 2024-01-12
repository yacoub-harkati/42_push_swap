CC = cc
CFLAGS= -Wall -Wextra -Werror
NAME = push_swap
BONUS_NAME = checker
SRCS = algorithm_utils.c algorithm.c error_check.c error_free.c finders.c \
       ft_split.c init_stack.c is_stack_sorted.c lst_utils.c push_commands.c \
       push_swap.c push_swap_utils.c rotate_commands.c small_sort.c \
       swap_commands.c reverse_rotate_commands.c setters.c \
       big_sort_algo.c big_sort_calc_a.c big_sort_sort.c big_sort_utils.c \
       big_sort_finders.c big_sort_apply_cmd.c big_sort_calc_b.c

SRCS_BONUS = algorithm_utils.c algorithm.c error_check.c error_free.c \
             finders.c ft_split.c init_stack.c is_stack_sorted.c lst_utils.c \
             push_commands.c checker_bonus.c push_swap_utils.c \
             rotate_commands.c small_sort.c swap_commands.c \
             reverse_rotate_commands.c setters.c

OBJS= $(SRCS:.c=.o)
OBJS_BONUS= $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) -Llibft -l:libft.a -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS_BONUS) -Llibft -l:libft.a -o $(BONUS_NAME)

clean:
	make clean -C libft
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME) $(BONUS_NAME)
	
re: fclean all

.SECONDARY: $(OBJS) $(OBJS_BONUS)
.PHONY: all clean fclean re