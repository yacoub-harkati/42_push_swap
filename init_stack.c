/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:48:34 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/13 17:23:43 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack_node **a, char **av, bool av_flag)
{
	int		i;
	long	number;

	i = 0;
	while (av[i])
	{
		number = ft_atoi(av[i]);
		if (!check_error(a, av[i], number))
		{
			if (av_flag)
				free_matrix(av);
			ft_putstr_fd("Error\n", 2);
			free_stack(a);
			exit(EXIT_FAILURE);
		}
		add_back_stack(a, new_stack(number));
		i++;
	}
	if (av_flag)
		free_matrix(av);
}
