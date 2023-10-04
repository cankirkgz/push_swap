/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 01:44:45 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/09/21 00:59:34 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_ultra(t_sort_list **stack_a, t_sort_list **stack_b)
{
	t_sort_list	*t_cheapest_a;
	t_sort_list	*t_cheapest_b;

	while (lstsize(*stack_a) != 3)
		pb(stack_a, stack_b, 0);
	three_sorter_a(stack_a);
	while (*stack_b)
	{
		add_index_and_above(stack_a);
		add_index_and_above(stack_b);
		calculate_target_node(stack_a, stack_b);
		t_cheapest_b = calculate_is_cheapest(stack_b);
		t_cheapest_a = t_cheapest_b->target_node;
		while (!control_is_top(stack_a, t_cheapest_b))
			push_b_to_a(stack_a, stack_b, t_cheapest_a, t_cheapest_b);
	}
	add_index_and_above(stack_a);
	while (!check_is_sorting(stack_a))
	{
		if (find_lowest(stack_a)->is_above == 1)
			ra(stack_a, 0, 0);
		else
			rra(stack_a, 0, 0);
	}
}
