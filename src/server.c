/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 06:54:47 by yoaoki            #+#    #+#             */
/*   Updated: 2025/04/18 07:07:06 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static int	bit = 0;
	static int	i = 0;

	(void)s;
	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == '\0')
		{
			kill(info->si_pid, SIGUSR2);
			write(1, "\n", 1);
		}
		else
		{
			write(1, &i, 1);
		}
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("[PID]: %d\n", pid);
	ft_printf("Waiting for a message...\n");
	sa.sa_sigaction = ft_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error: server sigaction\n");
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
