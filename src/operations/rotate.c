/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:52:57 by masantos          #+#    #+#             */
/*   Updated: 2026/02/19 19:52:57 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	if (!s || !*s || !(*s)->next)
		return (0);
	first = *s;
	*s = first->next;
	first->next = NULL;
	last = stack_last(*s);
	last->next = first;
	return (1);
}

void	ra(t_stack **a)
{
	if (rotate(a))
		write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	if (rotate(b))
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	int	changed;

	changed = 0;
	if (rotate(a))
		changed = 1;
	if (rotate(b))
		changed = 1;
	if (changed)
		write(1, "rr\n", 3);
}
