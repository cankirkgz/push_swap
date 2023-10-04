/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:18:37 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/09/19 17:03:12 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_is_top(t_sort_list **stack_a, \
		t_sort_list **stack_b, \
		t_sort_list *t_cheapest_a, \
		t_sort_list *t_cheapest_b)
{
	if (t_cheapest_a->is_above == 1 && t_cheapest_b->is_above == 1)
		rr(stack_a, stack_b, 0);
	else if (t_cheapest_a->is_above == 1 && t_cheapest_b->is_above == 0)
	{
		ra(stack_a, 0, 0);
		rrb(stack_b, 0, 0);
	}
	else if (t_cheapest_a->is_above == 0 && t_cheapest_b->is_above == 1)
	{
		rra(stack_a, 0, 0);
		rb(stack_b, 0, 0);
	}
	else
		rrr(stack_a, stack_b, 0);
}

void	push_b_to_a(t_sort_list **stack_a, \
		t_sort_list **stack_b, \
		t_sort_list *t_cheapest_a, \
		t_sort_list *t_cheapest_b)
{
	if (!control_is_top(stack_a, t_cheapest_a) && \
			!control_is_top(stack_b, t_cheapest_b))
	{
		check_if_is_top(stack_a, stack_b, t_cheapest_a, t_cheapest_b);
	}
	else if (!control_is_top(stack_a, t_cheapest_a) && \
			control_is_top(stack_b, t_cheapest_b))
	{
		if (t_cheapest_a->is_above == 1)
			ra(stack_a, 0, 0);
		else
			rra(stack_a, 0, 0);
	}
	else if (control_is_top(stack_a, t_cheapest_a) && \
			!control_is_top(stack_b, t_cheapest_b))
	{
		if (t_cheapest_b->is_above == 1)
			rb(stack_b, 0, 0);
		else
			rrb(stack_b, 0, 0);
	}
	else
		pa(stack_a, stack_b, 0);
}
