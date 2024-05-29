/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:38:50 by kgrosven          #+#    #+#             */
/*   Updated: 2024/02/14 09:41:50 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putlonghex_fd(unsigned long n, int fd)
{
	if (n >= 16)
		putlonghex_fd(n / 16, fd);
	n = (n % 16) + '0';
	if (n > '9')
		n += ('a' - '9' - 1);
	ft_putchar_fd(n, fd);
}

void	ft_putaddr_fd(void *ptr, int fd)
{
	ft_putstr_fd("0x", 1);
	putlonghex_fd((unsigned long) ptr, fd);
}
