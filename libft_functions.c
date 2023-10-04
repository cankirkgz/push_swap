/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 02:14:12 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/09/19 17:20:54 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	is_integer(long long num)
{
	if (-2147483648 <= num && num <= 2147483647)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			pos;
	long long	num;

	i = 0;
	pos = 1;
	num = 0;
	while (*str == 32 || *str == '\t' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == '\n' || *str == '\f')
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			pos *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (!is_integer(pos * num))
		ft_error();
	return (pos * num);
}

int	strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
