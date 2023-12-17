/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:55:09 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/17 16:55:24 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool is_stack_sorted(t_stack_node *lst)
{
	while (lst->next)
	{
		if (lst->value > lst->next->value)
			return (false);
		lst = lst->next;
	}
	return (true);
}