/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 02:07:02 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/09/18 14:12:02 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sort_list	*lstnew(int value)
{
	t_sort_list	*new;

	new = (t_sort_list *) malloc(sizeof(t_sort_list));
	if (!new)
		return (0);
	new->value = value;
	new->index = -1;
	new->next = 0;
	return (new);
}

t_sort_list	*lstlast(t_sort_list *lst)
{
	if (!lst)
		return (0);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	lstadd_back(t_sort_list **lst, t_sort_list *new)
{
	t_sort_list	*last;

	last = lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last -> next = new;
}

int	lstsize(t_sort_list *lst)
{
	int	size;

	size = 0;
	while (lst && ++size)
		lst = lst -> next;
	return (size);
}

void	lstadd_front(t_sort_list **lst, t_sort_list *new)
{
	new -> next = *lst;
	*lst = new;
}
