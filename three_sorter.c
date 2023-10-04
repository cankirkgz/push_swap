/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:48:21 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/09/19 17:02:32 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sorter_a(t_sort_list **stack_a)
{
	if (lstsize(*stack_a) != 3)
		return ;
	if (is_first_largest(stack_a))
	{
		ra(stack_a, 0, 0);
		if (!is_first_lowest(stack_a))
			sa(*stack_a, 0, 0);
	}
	else if (is_first_lowest(stack_a))
	{
		if (!is_last_largest(stack_a))
		{
			rra(stack_a, 0, 0);
			sa(*stack_a, 0, 0);
		}
	}
	else
	{
		if (is_last_largest(stack_a))
			sa(*stack_a, 0, 0);
		else
			rra(stack_a, 0, 0);
	}
}
