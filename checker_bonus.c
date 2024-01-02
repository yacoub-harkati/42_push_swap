/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:09:16 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/01 18:04:32 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_invalid_command(char *line, t_stack_node **a, t_stack_node **b)
{
	char	*src;

	src = "sa\nsb\nss\npa\npb\nra\nrb\nrr\nrra\nrrb\nrrr\n";
	if (ft_strlen(src) < 3 || !ft_strnstr(src, line, ft_strlen(src)))
	{
		free_stack(a);
		free_stack(b);
		free(line);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	apply_command(char *line, t_stack_node **a, t_stack_node **b,
		bool checker)
{
	if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
		sa(a, checker);
	else if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
		sb(b, checker);
	else if (!ft_strncmp(line, "ss\n", ft_strlen(line)))
		ss(a, b, checker);
	else if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
		pa(a, b, checker);
	else if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
		pb(a, b, checker);
	else if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
		ra(a, checker);
	else if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
		rb(b, checker);
	else if (!ft_strncmp(line, "rr\n", ft_strlen(line)))
		rr(a, b, checker);
	else if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
		rra(a, checker);
	else if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		rrb(b, checker);
	else if (!ft_strncmp(line, "rrr\n", ft_strlen(line)))
		rrr(a, b, checker);
}

void	read_and_sort_from_stdin(t_stack_node **a, t_stack_node **b,
		bool checker)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		handle_invalid_command(line, a, b);
		apply_command(line, a, b, checker);
		free(line);
	}
}

void	check_stack(t_stack_node **a, t_stack_node **b)
{
	if (is_stack_sorted(*a) && !*b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (EXIT_SUCCESS);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack(&a, av, ac == 2);
	b = NULL;
	read_and_sort_from_stdin(&a, &b, true);
	check_stack(&a, &b);
	free_stack(&a);
	return (EXIT_SUCCESS);
}
