/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:26:31 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/17 16:50:18 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void free_stack(t_stack_node **lst)
{
	t_stack_node *tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}