/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:48:20 by masantos          #+#    #+#             */
/*   Updated: 2026/02/19 19:48:20 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!from || !*from || !to)
		return (0);
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
	return (1);
}

void	pa(t_stack **a, t_stack **b)
{
	if (push(b, a))
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	if (push(a, b))
		write(1, "pb\n", 3);
}
