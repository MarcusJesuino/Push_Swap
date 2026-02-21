/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:50:32 by masantos          #+#    #+#             */
/*   Updated: 2026/02/19 19:50:32 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	swap(t_stack **s)
{
	t_stack	*first;
	t_stack	*second;

	if (!s || !*s || !(*s)->next)
		return (0);
	first = *s;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*s = second;
	return (1);
}

void	sa(t_stack **a)
{
	if (swap(a))
		write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	if (swap(b))
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	int	changed;

	changed = 0;
	if (swap(a))
		changed = 1;
	if (swap(b))
		changed = 1;
	if (changed)
		write(1, "ss\n", 3);
}
