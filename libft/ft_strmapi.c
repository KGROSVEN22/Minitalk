/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:13:00 by kgrosven          #+#    #+#             */
/*   Updated: 2024/02/14 09:33:03 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mapped;

	if (s == 0)
		return (0);
	i = 0;
	mapped = malloc(ft_strlen(s) + 1);
	if (mapped == 0)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		mapped[i] = f(i, s[i]);
		i++;
	}
	mapped[i] = 0;
	return (mapped);
}
