/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:32:29 by kgrosven          #+#    #+#             */
/*   Updated: 2024/02/13 11:34:30 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*ucs1;
	const unsigned char	*ucs2;
	size_t				i;

	ucs1 = (const unsigned char *) s1;
	ucs2 = (const unsigned char *) s2;
	i = 0;
	while (ucs1[i] != 0 || ucs2[i] != 0)
	{
		if (ucs1[i] != ucs2[i])
			return (ucs1[i] - ucs2[i]);
		i++;
	}
	return (0);
}
