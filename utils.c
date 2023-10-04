/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:59:30 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/10/02 23:44:47 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i + 1] != '\0')
			i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_is_sorting(t_sort_list **list)
{
	t_sort_list	*current;

	current = *list;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	check_has_same(t_sort_list **list)
{
	t_sort_list	*current;
	t_sort_list	*compare;

	current = *list;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->value == compare->value)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

t_sort_list	*find_lowest(t_sort_list **stack_a)
{
	t_sort_list	*t_lowest_value;
	t_sort_list	*current;
	int			current_value;

	t_lowest_value = *stack_a;
	current = *stack_a;
	while (current)
	{
		current_value = current->value;
		if (current_value < t_lowest_value->value)
			t_lowest_value = current;
		current = current->next;
	}
	return (t_lowest_value);
}
