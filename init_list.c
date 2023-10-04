/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:59:04 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/09/19 17:21:13 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_index_and_above(t_sort_list **stack)
{
	int			index;
	int			length;
	t_sort_list	*current;

	index = 0;
	length = lstsize(*stack);
	current = *stack;
	while (current)
	{
		current->index = index;
		calculate_push_price(stack);
		if (index <= length / 2)
			current->is_above = 1;
		else
			current->is_above = 0;
		index++;
		current = current->next;
	}
}

void	calculate_push_price(t_sort_list **stack)
{
	int			length;
	t_sort_list	*current;

	length = lstsize(*stack);
	current = *stack;
	if (length <= 1)
		return ;
	while (current)
	{
		if (current->index <= length / 2)
			current->push_price = current->index;
		else
			current->push_price = length - current->index;
		current = current->next;
	}
}
