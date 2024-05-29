/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strutils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:04:28 by kgrosven          #+#    #+#             */
/*   Updated: 2024/02/14 11:04:31 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_i_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_i_putstr(char *s)
{
	int	written;

	written = 0;
	while (*s != 0)
	{
		written = ft_add_check_error(written, ft_i_putchar(*s));
		if (written == -1)
			return (-1);
		s++;
	}
	return (written);
}
