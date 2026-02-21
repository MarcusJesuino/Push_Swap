/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 22:26:16 by masantos          #+#    #+#             */
/*   Updated: 2026/02/18 22:26:16 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	stack_add_front(t_stack **st, t_stack *new_node)
{
	if (!st || !new_node)
		return ;
	new_node->next = *st;
	*st = new_node;
}

int	stack_min(t_stack *st)
{
	int	min;

	if (!st)
		return (0);
	min = st->value;
	while (st)
	{
		if (st->value < min)
			min = st->value;
		st = st->next;
	}
	return (min);
}

int	stack_max(t_stack *st)
{
	int	max;

	if (!st)
		return (0);
	max = st->value;
	while (st)
	{
		if (st->value > max)
			max = st->value;
		st = st->next;
	}
	return (max);
}
