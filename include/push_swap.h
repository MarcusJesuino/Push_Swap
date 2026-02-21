/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:12:05 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 13:12:05 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* parse */
void	parse_args(int ac, char **av, t_stack **a);
void	ps_error(t_stack **a, int *vals, char **sp);
int		count_words(const char *s);
int		is_valid_token(const char *s);
int		atoi_checked(const char *s, int *out);
void	check_duplicates(int *vals, int total, t_stack **a);

/* stack */
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *st);
void	stack_add_back(t_stack **st, t_stack *new_node);
int		stack_size(t_stack *st);
void	stack_clear(t_stack **st);
int		is_sorted(t_stack *a);
void	stack_add_front(t_stack **st, t_stack *new_node);
int		stack_min(t_stack *st);
int		stack_max(t_stack *st);
void	index_stack(t_stack **a);

/* operations */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* sort */
void	radix_sort(t_stack **a, t_stack **b);
void	small_sort(t_stack **a, t_stack **b);
void	push_min_to_b(t_stack **a, t_stack **b);
void	sort_3(t_stack **a);

#endif