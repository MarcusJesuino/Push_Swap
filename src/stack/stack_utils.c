/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 22:26:11 by masantos          #+#    #+#             */
/*   Updated: 2026/02/18 22:26:11 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*n;

	n = (t_stack *)malloc(sizeof(t_stack));
	if (!n)
		return (NULL);
	n->value = value;
	n->index = -1;
	n->next = NULL;
	return (n);
}

t_stack	*stack_last(t_stack *st)
{
	if (!st)
		return (NULL);
	while (st->next)
		st = st->next;
	return (st);
}

void	stack_add_back(t_stack **st, t_stack *new_node)
{
	t_stack	*last;

	if (!st || !new_node)
		return ;
	if (!*st)
	{
		*st = new_node;
		return ;
	}
	last = stack_last(*st);
	last->next = new_node;
}

int	stack_size(t_stack *st)
{
	int	i;

	i = 0;
	while (st)
	{
		i++;
		st = st->next;
	}
	return (i);
}

void	stack_clear(t_stack **st)
{
	t_stack	*next;

	if (!st)
		return ;
	while (*st)
	{
		next = (*st)->next;
		free(*st);
		*st = next;
	}
}
