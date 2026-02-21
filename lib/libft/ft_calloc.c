/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:25:44 by masantos          #+#    #+#             */
/*   Updated: 2025/08/01 17:10:04 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*mem;
	unsigned char	*ptr;
	size_t			i;

	if (size == 0 || count == 0)
		return (malloc(1));
	if (size && count > (size_t)-1 / size)
		return (NULL);
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	i = 0;
	ptr = (unsigned char *)mem;
	while (i < count * size)
		ptr[i++] = (unsigned char) '\0';
	return (mem);
}
