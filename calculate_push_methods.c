/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_push_methods.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:49:07 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/09/18 14:27:28 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sort_list	*find_lowest_node(t_sort_list **stack)
{
	t_sort_list	*lowest_node;
	t_sort_list	*current;
	int			current_value;

	lowest_node = *stack;
	current = *stack;
	while (current)
	{
		current_value = current->value;
		if (current_value < lowest_node->value)
			lowest_node = current;
		current = current->next;
	}
	return (lowest_node);
}

void	calculate_target_node(t_sort_list **stack_a, t_sort_list **stack_b)
{
	t_sort_list	*current_b;
	t_sort_list	*current_a;
	t_sort_list	*min_node;

	current_b = *stack_b;
	while (current_b)
	{
		current_a = *stack_a;
		min_node = NULL;
		while (current_a)
		{
			if (current_a->value > current_b->value)
				if (!min_node || current_a->value < min_node->value)
					min_node = current_a;
			current_a = current_a->next;
		}
		if (!min_node)
			min_node = find_lowest_node(stack_a);
		current_b->target_node = min_node;
		current_b = current_b->next;
	}
}

t_sort_list	*calculate_is_cheapest(t_sort_list **stack_b)
{
	t_sort_list	*t_cheapest;
	t_sort_list	*current_b;
	int			cheapest;

	current_b = *stack_b;
	t_cheapest = *stack_b;
	cheapest = current_b->push_price + current_b->target_node->push_price;
	current_b = current_b->next;
	while (current_b)
	{
		if ((current_b->push_price + \
					current_b->target_node->push_price) < cheapest)
		{
			cheapest = current_b->push_price \
						+ current_b->target_node->push_price;
			t_cheapest = current_b;
		}
		current_b = current_b->next;
	}
	return (t_cheapest);
}

int	control_is_top(t_sort_list **stack, t_sort_list *cheapest)
{
	if ((*stack)->value == cheapest->value)
		return (1);
	return (0);
}
