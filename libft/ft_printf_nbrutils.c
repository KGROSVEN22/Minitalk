/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrutils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:04:13 by kgrosven          #+#    #+#             */
/*   Updated: 2024/02/14 11:04:15 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_i_putnbr(int n)
{
	int	written;

	written = 0;
	if (n == -2147483648)
		return (ft_i_putstr("-2147483648"));
	if (n < 0)
	{
		written = ft_add_check_error(written, ft_i_putchar('-'));
		if (written == -1)
			return (-1);
		n *= -1;
	}
	if (n >= 10)
		written = ft_add_check_error(written, ft_i_putnbr(n / 10));
	n = (n % 10) + '0';
	if (written == -1)
		return (-1);
	written = ft_add_check_error(written, ft_i_putchar(n));
	return (written);
}

int	ft_i_putunbr(unsigned int n)
{
	int	written;

	written = 0;
	if (n >= 10)
		written = ft_add_check_error(written, ft_i_putunbr(n / 10));
	n = (n % 10) + '0';
	if (written == -1)
		return (-1);
	written = ft_add_check_error(written, ft_i_putchar(n));
	return (written);
}
