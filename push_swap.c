/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:57:36 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/10/03 22:20:40 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_sort_list	*stack_a;
	t_sort_list	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	make_numeric(&stack_a, argv);
	check_argc_two(&stack_a);
	if ((!(valid_checker(argv)) || (check_has_same(&stack_a))))
		ft_error();
	if (check_is_sorting(&stack_a))
		return (0);
	add_index_and_above(&stack_a);
	sort_ultra(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
