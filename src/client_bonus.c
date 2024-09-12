/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshi <aoshi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 04:07:36 by yoaoki            #+#    #+#             */
/*   Updated: 2024/09/13 04:32:38 by aoshi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_confirm(int signal)
{
	(void)signal;
	ft_printf("received!\n");
}

void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

// TODO: 0とか-1とかオーバーフローする値のエラー処理
int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Error: wrong format\n");
		ft_printf("Try: ./client_bonus [PID] [Message]\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, ft_confirm);
	signal(SIGUSR2, ft_confirm);
	while (*argv[2])
	{
		ft_send_bits(pid, *argv[2]);
		argv[2]++;
	}
	ft_send_bits(pid, '\n');
	return (0);
}
