/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:13:28 by masantos          #+#    #+#             */
/*   Updated: 2026/02/19 22:13:28 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	get_max_index(t_stack *a)
{
	int	max;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	return (max);
}

static int	get_max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = get_max_index(a);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}
/*
** Processes one specific bit.
** Bit 0 elements go to stack B,
** bit 1 elements rotate inside A.
** Then all elements return to A.
*/
static void	radix_pass(t_stack **a, t_stack **b, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((*a)->index >> bit) & 1)
			ra(a);
		else
			pb(a, b);
		i++;
	}
	while (*b)
		pa(a, b);
}
/*
** Main algorithm for large inputs.
** Sorts elements using index bits.
** Repeats passes until all bits
** of the maximum index are processed.
*/
void	radix_sort(t_stack **a, t_stack **b)
{
	int	bit;
	int	max_bits;
	int	size;


	max_bits = get_max_bits(*a);
	size = stack_size(*a);
	bit = 0;
	while (bit < max_bits)
	{
		radix_pass(a, b, bit, size);
		if (is_sorted(*a))
			break ;
		bit++;
	}
}
