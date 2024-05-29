/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:40:13 by kgrosven          #+#    #+#             */
/*   Updated: 2024/02/14 09:37:49 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char		*ucs1;
	const unsigned char		*ucs2;
	size_t					i;

	ucs1 = (const unsigned char *) s1;
	ucs2 = (const unsigned char *) s2;
	i = 0;
	while ((ucs1[i] != 0 || ucs2[i] != 0) && i < n)
	{
		if (ucs1[i] != ucs2[i])
			return (ucs1[1] - ucs2[i]);
		i++;
	}
	return (0);
}
