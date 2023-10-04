/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:52:36 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/09/20 15:14:16 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_argc_two(t_sort_list **stack_a)
{
	if ((lstsize(*stack_a) == 2) && check_is_sorting(stack_a))
		return ;
	else if ((lstsize(*stack_a) == 2) && !check_is_sorting(stack_a))
		sa(*stack_a, 0, 0);
	else if ((lstsize(*stack_a) == 2) && !check_has_same(stack_a))
		ft_error();
}

void	make_numeric(t_sort_list **list, char **argv)
{
	int			i;
	int			j;
	char		**str;
	t_sort_list	*new_list;

	i = 1;
	while (argv[i])
	{
		str = ft_split(argv[i], ' ');
		j = 0;
		while (str[j])
		{
			new_list = lstnew(ft_atoi(str[j]));
			lstadd_back(list, new_list);
			j++;
		}
		free_double(str);
		i++;
	}
}

int	numeric_checker(char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**str;

	i = 1;
	count = 0;
	while (argv[i])
	{
		str = ft_split(argv[i], ' ');
		j = 0;
		while (str[j])
		{
			if (!(is_numeric(str[j])))
			{
				free_double(str);
				return (0);
			}
			j++;
			count++;
		}
		i++;
		free_double(str);
	}
	return (count);
}

int	is_all_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	valid_checker(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] == NULL) || \
				(ft_strncmp(argv[i], "", ft_strlen(argv[i])) == 0) \
				|| (is_all_space(argv[i])))
			return (0);
		i++;
	}
	if (!(numeric_checker(argv)))
		return (0);
	return (numeric_checker(argv));
}
