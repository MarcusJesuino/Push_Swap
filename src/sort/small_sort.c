/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:05:27 by masantos          #+#    #+#             */
/*   Updated: 2026/02/20 18:05:27 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	sort_4_5(t_stack **a, t_stack **b, int n)
{
	while (n > 3)
	{
		push_min_to_b(a, b);
		n--;
	}
	sort_3(a);
	while (*b)
		pa(a, b);
}

void	small_sort(t_stack **a, t_stack **b)
{
	int	n;

	n = stack_size(*a);
	if (n < 2 || is_sorted(*a))
		return ;
	if (n == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		return ;
	}
	if (n == 3)
		sort_3(a);
	else
		sort_4_5(a, b, n);
}
