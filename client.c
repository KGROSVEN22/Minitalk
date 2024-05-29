/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:07:01 by kgrosven          #+#    #+#             */
/*   Updated: 2024/05/10 11:40:23 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	send_signal(pid_t pid, char c)
{
	int		i;
	char	temp_c;

	i = 8;
	temp_c = c;
	while (i > 0)
	{
		i--;
		temp_c = c >> i;
		if ((temp_c & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(420);
	}
}

int	main(int ac, char *av[])
{
	pid_t	server_pid;
	char	*message;
	int		i;

	if (ac != 3)
	{
		ft_putstr_fd("./client <pid> <message>\n", 1);
		return (1);
	}
	message = av[2];
	server_pid = ft_atoi(av[1]);
	i = 0;
	while (message[i])
		send_signal(server_pid, message[i++]);
	send_signal(server_pid, '\0');
	return (0);
}
