/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:09:16 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/01 15:43:42 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **join_args(int ac, char **av)
{
	int i;
	char **args;
	char *tmp;
	
	i = 0;
	tmp = ft_strdup("");
	while (++i < ac)
	{
		if (!*av[i])
		{
			ft_putstr_fd("Error\n", 2);
			free(tmp);
			exit(EXIT_FAILURE);
		}
		tmp = ft_strjoin(tmp, " ");
		tmp = ft_strjoin(tmp, av[i]);
	}
	args = ft_split(tmp, ' ');
	free(tmp);
	return (args);
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
	init_stack(&a, av, true);
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
