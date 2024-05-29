/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:18:20 by kgrosven          #+#    #+#             */
/*   Updated: 2024/02/14 09:37:20 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	char	*tab;

	cc = (char) c;
	tab = 0;
	while (*s != 0)
	{
		if (*s == cc)
			tab = (char *) s;
		s++;
	}
	if (cc == 0)
		tab = (char *) s;
	return (tab);
}
