/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:38:37 by kgrosven          #+#    #+#             */
/*   Updated: 2024/02/14 11:31:06 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	uc;
	size_t			i;

	i = 0;
	str = (unsigned char *) s;
	uc = (unsigned char) c;
	while (i < n)
	{
		if (str[i] == uc)
			return (str + i);
		i++;
	}
	return (0);
}
