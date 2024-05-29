/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:42:29 by kgrosven          #+#    #+#             */
/*   Updated: 2024/02/14 09:57:06 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	overflow;

	if (count == 0 || size == 0)
		return (malloc(0));
	overflow = count * size;
	if (overflow / count != size)
		return (0);
	ptr = malloc(overflow);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, overflow);
	return (ptr);
}
