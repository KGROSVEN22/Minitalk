/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexutils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:03:48 by kgrosven          #+#    #+#             */
/*   Updated: 2024/02/14 11:03:55 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_i_puthex(unsigned int n, int use_capitals)
{
	int	written;
	int	dif;

	written = 0;
	if (n >= 16)
		written = ft_add_check_error(written,
				ft_i_puthex(n / 16, use_capitals));
	if (use_capitals)
		dif = ('A' - '9' - 1);
	else
		dif = ('a' - '9' - 1);
	n = (n % 16) + '0';
	if (n > '9')
		n += dif;
	if (written == -1)
		return (-1);
	written = ft_add_check_error(written, ft_i_putchar(n));
	return (written);
}

static int	i_putlonghex(unsigned long n)
{
	int	written;

	written = 0;
	if (n >= 16)
		written = ft_add_check_error(written, i_putlonghex(n / 16));
	n = (n % 16) + '0';
	if (n > '9')
		n += ('a' - '9' - 1);
	if (written == -1)
		return (-1);
	written = ft_add_check_error(written, ft_i_putchar(n));
	return (written);
}

int	ft_i_putaddr(void *ptr)
{
	int	written;

	written = ft_i_putstr("0x");
	if (written == -1)
		return (-1);
	written = ft_add_check_error(written, i_putlonghex((unsigned long) ptr));
	return (written);
}
