/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:35:40 by masantos          #+#    #+#             */
/*   Updated: 2026/02/20 18:35:40 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_3(t_stack **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

static int	pos_of_value(t_stack *a, int value)
{
	int	pos;

	pos = 0;
	while (a && a->value != value)
	{
		pos++;
		a = a->next;
	}
	return (pos);
}

static void	rotate_to_top(t_stack **a, int value)
{
	int	pos;
	int	size;

	size = stack_size(*a);
	pos = pos_of_value(*a, value);
	while ((*a)->value != value)
	{
		if (pos <= size / 2)
			ra(a);
		else
			rra(a);
	}
}

void	push_min_to_b(t_stack **a, t_stack **b)
{
	int	min;

	min = stack_min(*a);
	rotate_to_top(a, min);
	pb(a, b);
}
