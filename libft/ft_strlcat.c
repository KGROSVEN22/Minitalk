/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:52:30 by kgrosven          #+#    #+#             */
/*   Updated: 2024/02/13 11:44:52 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	j;
	size_t	i;

	i = 0;
	while (dest != 0 && dest[i] != 0 && i < destsize)
	{
		i++;
	}
	j = 0;
	while (src[j] != 0)
	{
		if (i + j < destsize - 1 && destsize != 0)
			dest[i + j] = src[j];
		if (i + j == destsize - 1 && destsize != 0)
			dest[i + j] = 0;
		j++;
	}
	if (i + j <= destsize - 1 && destsize != 0)
		dest[i + j] = 0;
	return (i + j);
}
