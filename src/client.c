#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void ft_confirm(int signal, siginfo_t *info, void *s) {
	(void)info;
	(void)s;
	(void)signal;
	printf("Message received!\n");
}

void ft_send_bits(int pid, char i) {
	int bit;

	bit = 0;
	while (bit < 8) {
		if ((i & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		// これもusleep(1)でもあれば今の所動作する。
		// 割り込み中にもう一方のシグナルが発生するとバグる(文字化け？)
		usleep(100); // レースコンディション対策って何？
		bit++;
	}
}

int main(int argc, char **argv) {
	int pid;
	struct sigaction sa;

	sa.sa_sigaction = ft_confirm;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR2, &sa, NULL);

	if (argc != 3) {
		printf("Usage: ./client [PID] [Message]\n");
		return (1);
	}

	pid = atoi(argv[1]);
	if (pid <= 0 || kill(pid, 0) == -1) {
		printf("Error: PID not valid\n");
		exit(1);
	}
	while (*argv[2]) {
		ft_send_bits(pid, *argv[2]);
		argv[2]++;
	}
	ft_send_bits(pid, '\0');
	return (0);
}
