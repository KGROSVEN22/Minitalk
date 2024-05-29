/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:10:59 by kgrosven          #+#    #+#             */
/*   Updated: 2024/02/22 11:03:16 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char const	*get_next_split(char const *s, char c)
{
	while (*s != 0)
	{
		if (*s == c)
			break ;
		s++;
	}
	return (s);
}

static void	free_all(char **strs, size_t *iptr)
{
	size_t	i;

	i = 0;
	while (i < *iptr)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static int	add_to_strs(char **strs, char const *s, size_t len, size_t *iptr)
{
	if (len == 0)
		return (1);
	strs[*iptr] = ft_substr(s, 0, len);
	if (strs[*iptr] == 0)
		return (0);
	*iptr += 1;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**strs;
	size_t		i;
	const char	*tab;

	strs = NULL;
	if (s == 0)
		return (0);
	i = 0;
	while (*s != 0)
	{
		tab = get_next_split(s, c);
		if (add_to_strs(strs, s, tab - s, &i) == 0)
		{
			free_all(strs, &i);
			return (0);
		}
		if (*tab != 0)
			tab++;
		s = tab;
	}
	strs[i] = 0;
	return (strs);
}
