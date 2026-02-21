/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 21:25:41 by masantos          #+#    #+#             */
/*   Updated: 2026/02/19 21:25:41 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	run_sort(t_stack **a, t_stack **b)
{
	int	n;

	if (is_sorted(*a))
		return ;
	n = stack_size(*a);
	if (n <= 5)
		small_sort(a, b);
	else
	{
		index_stack(a);
		radix_sort(a, b);
	}
}

/*
** Program entry point.
** Parses arguments and builds stack A.
** Chooses the sorting strategy:
** small_sort for small inputs
** or radix_sort for larger ones.
*/
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	parse_args(ac, av, &a);
	run_sort(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}

/*
a test made by myself to test the results

#!/bin/bash
ARG=$(seq 1 500 | shuf | tr '\n' ' ')

echo "Testando 100 números..."
echo

OPS=$(./push_swap $ARG)
COUNT=$(echo "$OPS" | wc -l)

echo "$OPS" | ./checker_linux $ARG
echo
echo "Operações: $COUNT"
*/