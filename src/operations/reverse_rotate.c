/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:54:06 by masantos          #+#    #+#             */
/*   Updated: 2026/02/19 19:54:06 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	reverse_rotate(t_stack **s)
{
	t_stack	*prev;
	t_stack	*last;

	if (!s || !*s || !(*s)->next)
		return (0);
	prev = *s;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *s;
	*s = last;
	return (1);
}

void	rra(t_stack **a)
{
	if (reverse_rotate(a))
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	if (reverse_rotate(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	int	changed;

	changed = 0;
	if (reverse_rotate(a))
		changed = 1;
	if (reverse_rotate(b))
		changed = 1;
	if (changed)
		write(1, "rrr\n", 4);
}
