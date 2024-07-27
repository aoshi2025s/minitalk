/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:33:57 by yoaoki            #+#    #+#             */
/*   Updated: 2024/07/28 00:37:12 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	send_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		printf("Error: wrong format.\n");
		printf("Try: ./client [PID] [MESSAGE]\n");
		return (1);
	}
	pid = atoi(argv[1]);
	while (*argv[2])
	{
		send_bits(pid, *argv[2]);
		argv[2]++;
	}
	send_bits(pid, '\n');
	return (0);
}
