/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:05:42 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/10/03 22:20:04 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <signal.h>

typedef struct s_sort_list
{
	int					value;
	int					index;
	int					is_above;
	int					push_price;
	int					is_cheapest;
	struct s_sort_list	*next;
	struct s_sort_list	*target_node;
}					t_sort_list;

int			ft_isdigit(int c);
int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
int			valid_checker(char **argv);
int			check_is_sorting(t_sort_list **list);
void		add_index_and_above(t_sort_list **stack);
void		make_numeric(t_sort_list **list, char **argv);
void		check_argc_two(t_sort_list **stack_a);
int			is_numeric(char *str);
void		ft_error(void);
int			check_has_same(t_sort_list **list);
t_sort_list	*find_lowest(t_sort_list **stack_a);
t_sort_list	*lstnew(int value);
void		lstadd_back(t_sort_list **lst, t_sort_list *new);
int			lstsize(t_sort_list *lst);
t_sort_list	*lstlast(t_sort_list *lst);
void		lstadd_front(t_sort_list **lst, t_sort_list *new);
int			strcmp(const char *s1, const char *s2);
void		sa(t_sort_list *stack_a, int flag_ss, int is_checker);
void		sb(t_sort_list *stack_b, int flag_ss, int is_checker);
void		rra(t_sort_list **stack_a, int flag_rrr, int is_checker);
void		pa(t_sort_list **stack_a, t_sort_list **stack_b, int is_checker);
void		pb(t_sort_list **stack_a, t_sort_list **stack_b, int is_checker);
void		ra(t_sort_list **stack_a, int flag_rr, int is_checker);
void		rb(t_sort_list **stack_b, int flag_rr, int is_checker);
void		rrb(t_sort_list **stack_b, int flag_rrr, int is_checker);
void		rr(t_sort_list **stack_a, t_sort_list **stack_b, int is_checker);
void		rrr(t_sort_list **stack_a, t_sort_list **stack_b, int is_checker);
void		ss(t_sort_list *stack_a, t_sort_list *stack_b, int is_checker);
int			is_first_largest(t_sort_list **stack_a);
int			is_last_largest(t_sort_list **stack_a);
int			is_first_lowest(t_sort_list **stack_a);
void		three_sorter_a(t_sort_list **stack_a);
void		sort_ultra(t_sort_list **stack_a, t_sort_list **stack_b);
void		calculate_target_node(t_sort_list **stack_a, t_sort_list **stack_b);
void		calculate_push_price(t_sort_list **stack);
t_sort_list	*calculate_is_cheapest(t_sort_list **stack_b);
int			control_is_top(t_sort_list **stack, t_sort_list *cheapest);
void		push_b_to_a(t_sort_list **stack_a, \
		t_sort_list **stack_b, \
		t_sort_list *t_cheapest_a, \
		t_sort_list *t_cheapest_b);
void		free_stacks(t_sort_list **stack_a, t_sort_list **stack_b);
void		free_double(char **str);
void		free_stack(t_sort_list *stack);
int			stack_len(t_sort_list *stack);

#endif
