/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_and_last.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:04:31 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/09/18 14:06:33 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_first_largest(t_sort_list **stack_a)
{
	int			max_value;
	t_sort_list	*current;

	if (!stack_a || !(*stack_a))
		return (0);
	max_value = (*stack_a)->value;
	current = *stack_a;
	while (current)
	{
		if (current->value > max_value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_first_lowest(t_sort_list **stack_a)
{
	int			min_value;
	t_sort_list	*current;

	if (!stack_a || !(*stack_a))
		return (1);
	min_value = (*stack_a)->value;
	current = *stack_a;
	while (current)
	{
		if (current->value < min_value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_last_largest(t_sort_list **stack_a)
{
	int			max_value;
	t_sort_list	*current;

	if (!stack_a || !(*stack_a))
		return (0);
	max_value = (*stack_a)->value;
	current = *stack_a;
	while (current->next)
	{
		current = current->next;
		if (current->value > max_value)
			max_value = current->value;
	}
	if (current->value > max_value)
		max_value = current->value;
	if (max_value == current->value)
		return (1);
	return (0);
}
