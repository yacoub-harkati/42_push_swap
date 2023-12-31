/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:09:16 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/31 23:35:54 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **join_args(int ac, char **av)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (!av[i])
		{
			ft_putstr_fd("Error\n", 2);
			if (i > 2)
				free(av[1]);
			exit(EXIT_FAILURE);
		}
		av[1] = ft_strjoin(av[1], " ");
		av[1] = ft_strjoin(av[1], av[i]);
	}
	return (ft_split(av[1], ' '));
}

int main(int ac, char **av)
{
	t_stack_node *a;
	t_stack_node *b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (EXIT_FAILURE);
	av = join_args(ac, av);
	init_stack(&a, av, ac == 2);
	if (!is_stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, false);
		else if (stack_size(a) == 3)
			sort_three(&a, false);
		else if (stack_size(a) <= 5)
			sort_five(&a, &b, false);
		else
			push_swap(&a, &b, false);
	}
	free_stack(&a);
	return (EXIT_SUCCESS);
}
