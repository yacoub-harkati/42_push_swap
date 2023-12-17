/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:26:31 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/17 15:29:17 by yaharkat         ###   ########.fr       */
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