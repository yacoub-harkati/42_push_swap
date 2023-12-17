/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:28:16 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/17 16:51:07 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool check_error(t_stack_node **a, char *av, long number)
{
	if (!check_digit(av) || !check_int(number) || !check_duplicate(*a, number))
		return false;
	return true;
}

bool check_digit(char *av)
{
	int i;

	i = 0;
	if (av[0] == '-')
		i++;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return false;
		i++;
	}
	return true;
}
bool check_int(long number)
{
	if (number > INT_MAX || number < INT_MIN)
		return false;
	return true;
}

bool check_duplicate(t_stack_node *a, int number)
{
	t_stack_node *tmp;

	if (!a)
		return true;
	tmp = a;
	while (tmp)
	{
		if (tmp->value == number)
			return false;
		tmp = tmp->next;
	}
	return true;
}
