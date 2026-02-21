/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 21:25:21 by masantos          #+#    #+#             */
/*   Updated: 2026/02/19 21:25:21 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	*stack_to_array(t_stack **a, int n)
{
	int		*arr;
	int		i;
	t_stack	*tmp;

	arr = malloc(sizeof(int) * n);
	if (!arr)
		ps_error(a, NULL, NULL);
	tmp = *a;
	i = 0;
	while (i < n)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

static void	int_swap(int *x, int *y)
{
	int	t;

	t = *x;
	*x = *y;
	*y = t;
}

static void	sort_ints(int *arr, int l, int r)
{
	int	i;
	int	j;
	int	p;

	i = l;
	j = r;
	p = arr[(l + r) / 2];
	while (i <= j)
	{
		while (arr[i] < p)
			i++;
		while (arr[j] > p)
			j--;
		if (i <= j)
		{
			int_swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}
	if (l < j)
		sort_ints(arr, l, j);
	if (i < r)
		sort_ints(arr, i, r);
}

static int	find_pos(int *arr, int n, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

/*
** Assigns sorted indexes to nodes.
** Converts stack to array, sorts it,
** and maps each value to its position.
** Required for radix sorting.
*/
void	index_stack(t_stack **a)
{
	int		n;
	int		*arr;
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	n = stack_size(*a);
	arr = stack_to_array(a, n);
	sort_ints(arr, 0, n - 1);
	tmp = *a;
	while (tmp)
	{
		tmp->index = find_pos(arr, n, tmp->value);
		tmp = tmp->next;
	}
	free(arr);
}
