/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:05:20 by masantos          #+#    #+#             */
/*   Updated: 2026/02/18 17:05:20 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	int_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
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

static int	*dup_array(int *vals, int total, t_stack **a)
{
	int	*tmp;
	int	i;

	tmp = (int *)malloc(sizeof(int) * total);
	if (!tmp)
		ps_error(a, vals, NULL);
	i = 0;
	while (i < total)
	{
		tmp[i] = vals[i];
		i++;
	}
	return (tmp);
}

static void	check_neighbors(int *arr, int total, t_stack **a, int *vals)
{
	int	i;

	i = 1;
	while (i < total)
	{
		if (arr[i] == arr[i - 1])
		{
			free(arr);
			ps_error(a, vals, NULL);
		}
		i++;
	}
}
/*
** Detects duplicated values.
** Copies and sorts the array,
** then compares neighboring elements.
** Triggers error if duplicates exist.
*/
void	check_duplicates(int *vals, int total, t_stack **a)
{
	int	*tmp;

	tmp = dup_array(vals, total, a);
	sort_ints(tmp, 0, total - 1);
	check_neighbors(tmp, total, a, vals);
	free(tmp);
}
