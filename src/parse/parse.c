/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:45:36 by masantos          #+#    #+#             */
/*   Updated: 2026/02/18 16:45:36 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	free_split(char **sp)
{
	int	i;

	i = 0;
	while (sp && sp[i])
		free(sp[i++]);
	free(sp);
}
/*
** Counts how many numbers exist
** across all program arguments.
** Used to allocate the values array.
*/
static int	count_total_tokens(int ac, char **av)
{
	int	i;
	int	total;

	i = 1;
	total = 0;
	while (i < ac)
		total += count_words(av[i++]);
	return (total);
}
/*
** Builds stack A from the integer array.
** Creates nodes and appends them
** preserving the original order.
*/
static void	build_stack(t_stack **a, int *vals, int total)
{
	int		i;
	t_stack	*n;

	i = 0;
	while (i < total)
	{
		n = stack_new(vals[i]);
		if (!n)
			ps_error(a, vals, NULL);
		stack_add_back(a, n);
		i++;
	}
}
/*
** Iterates through all arguments.
** Splits strings into tokens,
** validates each number and converts it.
** Stores values inside a temporary array.
*/
static void	fill_values(int ac, char **av, int *vals, t_stack **a)
{
	int		i;
	int		j;
	int		k;
	int		v;
	char	**sp;

	i = 1;
	k = 0;
	while (i < ac)
	{
		if (count_words(av[i]) == 0)
			ps_error(a, vals, NULL);
		sp = ft_split(av[i++], ' ');
		if (!sp)
			ps_error(a, vals, NULL);
		j = -1;
		while (sp[++j])
		{
			if (!is_valid_token(sp[j]) || !atoi_checked(sp[j], &v))
				ps_error(a, vals, sp);
			vals[k++] = v;
		}
		free_split(sp);
	}
}

/*
** Main parsing function.
** Counts tokens, validates input,
** converts values to integers,
** and builds the initial stack.
** Also checks for duplicates.
*/
void	parse_args(int ac, char **av, t_stack **a)
{
	int	total;
	int	*vals;

	total = count_total_tokens(ac, av);
	if (total == 0)
		ps_error(a, NULL, NULL);
	vals = (int *)malloc(sizeof(int) * total);
	if (!vals)
		ps_error(a, NULL, NULL);
	fill_values(ac, av, vals, a);
	check_duplicates(vals, total, a);
	build_stack(a, vals, total);
	free(vals);
}
