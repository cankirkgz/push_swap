/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:39:22 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/10/03 22:19:23 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_sort_list *stack_a, int flag_ss, int is_checker)
{
	int	tmp;

	if (stack_a && stack_a->next)
	{
		tmp = stack_a->value;
		stack_a->value = stack_a->next->value;
		stack_a->next->value = tmp;
	}
	if (!is_checker)
		if (!flag_ss)
			ft_putstr_fd("sa\n", 1);
}

void	pa(t_sort_list **stack_a, t_sort_list **stack_b, int is_checker)
{
	t_sort_list	*top_b;

	if (!stack_b || !(*stack_b))
		return ;
	top_b = *stack_b;
	*stack_b = top_b->next;
	top_b->next = *stack_a;
	*stack_a = top_b;
	if (!is_checker)
		ft_putstr_fd("pa\n", 1);
}

void	ra(t_sort_list **stack_a, int flag_rr, int is_checker)
{
	t_sort_list	*top_a;
	t_sort_list	*current;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	top_a = *stack_a;
	*stack_a = top_a->next;
	current = *stack_a;
	while (current->next)
	{
		current = current->next;
	}
	current->next = top_a;
	top_a->next = NULL;
	if (!is_checker)
		if (!flag_rr)
			ft_putstr_fd("ra\n", 1);
}

void	rra(t_sort_list **stack_a, int flag_rrr, int is_checker)
{
	t_sort_list	*last;
	t_sort_list	*current;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	last = NULL;
	current = *stack_a;
	while (current->next)
	{
		last = current;
		current = current->next;
	}
	last->next = NULL;
	current->next = *stack_a;
	*stack_a = current;
	if (!is_checker)
		if (!flag_rrr)
			ft_putstr_fd("rra\n", 1);
}
