/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 01:16:32 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/09/21 01:31:00 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_sort_list *stack_b, int flag_ss, int is_checker)
{
	int	tmp;

	if (stack_b && stack_b->next)
	{
		tmp = stack_b->value;
		stack_b->value = stack_b->next->value;
		stack_b->next->value = tmp;
	}
	if (!is_checker)
		if (!flag_ss)
			ft_putstr_fd("sb\n", 1);
}

void	pb(t_sort_list **stack_a, t_sort_list **stack_b, int is_checker)
{
	t_sort_list	*top_a;

	if (!(*stack_a) || !stack_b)
		return ;
	top_a = *stack_a;
	*stack_a = top_a->next;
	top_a->next = *stack_b;
	*stack_b = top_a;
	add_index_and_above(stack_a);
	add_index_and_above(stack_b);
	if (!is_checker)
		ft_putstr_fd("pb\n", 1);
}

void	rb(t_sort_list **stack_b, int flag_rr, int is_checker)
{
	t_sort_list	*top_b;
	t_sort_list	*current;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	top_b = *stack_b;
	*stack_b = top_b->next;
	current = *stack_b;
	while (current->next)
	{
		current = current->next;
	}
	current->next = top_b;
	top_b->next = NULL;
	if (!is_checker)
		if (!flag_rr)
			ft_putstr_fd("rb\n", 1);
}

void	rrb(t_sort_list **stack_b, int flag_rrr, int is_checker)
{
	t_sort_list	*last;
	t_sort_list	*current;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	last = NULL;
	current = *stack_b;
	while (current->next)
	{
		last = current;
		current = current->next;
	}
	last->next = NULL;
	current->next = *stack_b;
	*stack_b = current;
	if (!is_checker)
		if (!flag_rrr)
			ft_putstr_fd("rrb\n", 1);
}
