/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 01:27:06 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/09/19 17:15:10 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_sort_list *stack_a, t_sort_list *stack_b, int is_checker)
{
	sa(stack_a, 1, is_checker);
	sb(stack_b, 1, is_checker);
	if (!is_checker)
		ft_putstr_fd("ss\n", 1);
}

void	rr(t_sort_list **stack_a, t_sort_list **stack_b, int is_checker)
{
	ra(stack_a, 1, is_checker);
	rb(stack_b, 1, is_checker);
	if (!is_checker)
		ft_putstr_fd("rr\n", 1);
}

void	rrr(t_sort_list **stack_a, t_sort_list **stack_b, int is_checker)
{
	rra(stack_a, 1, is_checker);
	rrb(stack_b, 1, is_checker);
	if (!is_checker)
		ft_putstr_fd("rrr\n", 1);
}
