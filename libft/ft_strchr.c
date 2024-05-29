/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:12:11 by kgrosven          #+#    #+#             */
/*   Updated: 2024/02/13 11:31:49 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = (char) c;
	while (*s != 0)
	{
		if (*s == cc)
			return ((char *) s);
		s++;
	}
	if (cc == 0)
		return ((char *) s);
	return (0);
}
