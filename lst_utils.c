/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:43:57 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/13 14:43:57 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_lstlast(t_stack_node *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_front(t_stack_node **lst, t_stack_node *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_stack_node	*ft_lstnew(void *content)
{
	t_stack_node	*list;

	list = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

int	ft_lstsize(t_stack_node *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		lst = lst->next;
		counter++;
	}
	return (counter);
}

void	ft_lstdelone(t_stack_node *lst, void (*del)(t_stack_node *))
{
	if (lst)
	{
		if (del)
			del(lst);
		free(lst);
	}
}

void	ft_lstclear(t_stack_node **lst, void (*del)(void *))
{
	t_stack_node	*temp;

	if (lst)
	{
		if (*lst)
		{
			while (*lst)
			{
				temp = (*lst)->next;
				ft_lstdelone(*lst, del);
				*lst = temp;
			}
		}
		lst = NULL;
	}
}

void	ft_lstadd_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
		{
			*lst = new;
		}
	}
}
