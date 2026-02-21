/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:05:24 by masantos          #+#    #+#             */
/*   Updated: 2026/02/18 17:05:24 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
** Checks if a token is a valid number.
** Accepts optional '+' or '-' sign.
** Ensures remaining characters are digits.
*/
int	is_valid_token(const char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	check_limit_next(long res, int sign, int digit)
{
	if (res > 214748364)
		return (0);
	if (res == 214748364 && sign == 1 && digit > 7)
		return (0);
	if (res == 214748364 && sign == -1 && digit > 8)
		return (0);
	return (1);
}

/*
** Safe string-to-int conversion.
** Detects overflow and underflow
** before the value exceeds int limits.
*/
int	atoi_checked(const char *s, int *out)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		if (!check_limit_next(res, sign, s[i] - '0'))
			return (0);
		res = res * 10 + (s[i] - '0');
		i++;
	}
	*out = (int)(res * sign);
	return (1);
}
