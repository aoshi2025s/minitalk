/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshi <aoshi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 04:07:44 by yoaoki            #+#    #+#             */
/*   Updated: 2024/09/13 04:32:44 by aoshi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_handler(int signal, siginfo_t *info, void *dummy)
{
	static int	bit;
	static int	c;

	(void)info;
	(void)dummy;
	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

// TODO: aoti overflow -1, 0
int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: wrong format\n");
		ft_printf("Try: ./server_bonus\n");
		return (1);
	}
	ft_printf("[PID]: %d\n", getpid());
	ft_printf("Waiting for a message...\n");
	sa.sa_sigaction = ft_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
