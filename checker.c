/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:27:10 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/10/03 22:24:41 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_result(t_sort_list **a, t_sort_list **b, char c)
{
	if (c == 'o')
		write(1, "OK\n", 3);
	else if (c == 'k')
		write(1, "KO\n", 3);
	if (c == 'o' || c == 'k')
	{
		free_stack(*a);
		free_stack(*b);
		exit(0);
	}
}

int	is_sorting_needed(t_sort_list *stack)
{
	if (!stack)
		return (0);
	while (stack && stack->next)
	{
		if (stack->next->value < stack->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	apply_rule_2(t_sort_list **stack_a, \
		t_sort_list **stack_b, char *command)
{
	if (!strcmp("rra\n", command) && command)
		rra(stack_a, 0, 1);
	else if (!strcmp("rrb\n", command) && command)
		rrb(stack_b, 0, 1);
	else if (!strcmp("rrr\n", command) && command)
		rrr(stack_a, stack_b, 1);
	else if (!strcmp("ra\n", command) && command)
		ra(stack_a, 0, 1);
	else if (!strcmp("rb\n", command) && command)
		rb(stack_b, 0, 1);
	else if (!strcmp("rr\n", command) && command)
		rr(stack_a, stack_b, 1);
	else if (command)
		ft_error();
}

void	apply_rule(t_sort_list **stack_a, t_sort_list **stack_b, char *command)
{
	if (!command && !is_sorting_needed(*stack_a))
		write_result(stack_a, stack_b, 'k');
	if (!command && is_sorting_needed(*stack_a) && stack_len(*stack_b) == 0)
		write_result(stack_a, stack_b, 'o');
	if (!command && stack_len(*stack_b) > 0)
		write_result(stack_a, stack_b, 'k');
	if (!(strcmp("sa\n", command)) && command)
		sa(*stack_a, 0, 1);
	else if (!strcmp("sb\n", command) && command)
		sb(*stack_b, 0, 1);
	else if (!strcmp("ss\n", command) && command)
		ss(*stack_a, *stack_b, 1);
	else if (!strcmp("pa\n", command) && command)
		pa(stack_a, stack_b, 1);
	else if (!strcmp("pb\n", command) && command)
		pb(stack_a, stack_b, 1);
	else
		apply_rule_2(stack_a, stack_b, command);
}

int	main(int argc, char *argv[])
{
	t_sort_list	*stack_a;
	t_sort_list	*stack_b;
	char		*command;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	else
		make_numeric(&stack_a, argv);
	if ((!(valid_checker(argv)) || (check_has_same(&stack_a))))
		ft_error();
	if (argc > 1)
	{
		while (1)
		{
			command = get_next_line(0);
			apply_rule(&stack_a, &stack_b, command);
			free(command);
		}
	}
	else
		return (0);
}
