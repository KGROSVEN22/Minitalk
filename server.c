/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:07:30 by kgrosven          #+#    #+#             */
/*   Updated: 2024/05/27 12:54:25 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static char	current_char;
	static int	bit_i;

	(void)context;
	current_char = current_char | (signal == SIGUSR1);
	bit_i++;
	if (bit_i == 8)
	{
		if (current_char == '\0')
		{
			ft_putchar_fd('\n', 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
			ft_putchar_fd(current_char, 1);
		bit_i = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
}

/*int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("my pid is: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}*/

int	main(void)
{
pid_t                pid;
    struct sigaction    s_a;

    pid = getpid();
    ft_putstr_fd("PID is = ", 1);
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
    ft_memset(&s_a, 0, sizeof(s_a));
    s_a.sa_sigaction = handle_signal;
    s_a.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &s_a, 0);
    sigaction(SIGUSR2, &s_a, 0);
    while (1)
        pause();
    return (0);
}
