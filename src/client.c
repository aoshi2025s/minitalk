/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 06:54:30 by yoaoki            #+#    #+#             */
/*   Updated: 2025/04/20 17:42:53 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack = 0;

// use async-signal safe function (do not use printf)
void	ft_confirm(int signal, siginfo_t *info, void *s)
{
	(void)info;
	(void)s;
	if (signal == SIGUSR2)
		write(1, "Message received!\n", 18);
	if (signal == SIGUSR1)
		g_ack = 1;
}

void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_ack = 0;
		if ((i & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_ack == 0)
			pause();
		usleep(100);
		bit++;
	}
}

int	ft_get_pid(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [PID] [Message]\n");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || kill(pid, 0) == -1)
	{
		ft_printf("Error: PID not valid\n");
		exit(1);
	}
	return (pid);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = ft_confirm;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR2, &sa, NULL) == -1
		|| sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error client sigaction\n");
		exit(1);
	}
	pid = ft_get_pid(argc, argv);
	while (*argv[2])
	{
		ft_send_bits(pid, *argv[2]);
		argv[2]++;
	}
	ft_send_bits(pid, '\0');
	return (0);
}
