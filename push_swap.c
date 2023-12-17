/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:09:16 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/13 12:09:16 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{

	t_stack_node *a;
	t_stack_node *b;

	a = NULL;
	b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (EXIT_FAILURE);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack(&a, av, ac == 2);
	b = last_stack(a);
	printf("a: %d\n", b->value);
}