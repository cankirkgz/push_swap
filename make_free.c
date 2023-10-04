/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:28:41 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/10/03 01:26:12 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_sort_list **stack_a, t_sort_list **stack_b)
{
	t_sort_list	*tmp;

	if (stack_a && (*stack_a))
	{
		while (*stack_a)
		{
			tmp = (*stack_a)->next;
			free(*stack_a);
			*stack_a = tmp;
		}
		*stack_a = NULL;
	}
	if (stack_b && (*stack_b))
	{
		while (*stack_b)
		{
			tmp = (*stack_b)->next;
			free(*stack_b);
			*stack_b = tmp;
		}
		*stack_b = NULL;
	}
}

void	free_double(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
