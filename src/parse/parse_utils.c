/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:37:29 by masantos          #+#    #+#             */
/*   Updated: 2026/02/18 17:37:29 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ps_error(t_stack **a, int *vals, char **sp)
{
	int	i;

	if (sp)
	{
		i = 0;
		while (sp[i])
			free(sp[i++]);
		free(sp);
	}
	if (vals)
		free(vals);
	if (a)
		stack_clear(a);
	write(2, "Error\n", 6);
	exit(1);
}

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	count_words(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		while (s[i] && is_space(s[i]))
			i++;
		if (s[i])
			count++;
		while (s[i] && !is_space(s[i]))
			i++;
	}
	return (count);
}
