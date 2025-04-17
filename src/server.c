#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// TODO: 非同期安全な関数とは？

void ft_handler(int signal, siginfo_t *info, void *s) {
	static int bit = 0;
	static int i = 0;

	(void)s;
	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8) {
		if (i == '\0') {
			kill(info->si_pid, SIGUSR2);
			write(1, "\n", 1);
		} else {
			write(1, &i, 1);
		}
		bit = 0;
		i = 0;
	}
}

int main(void) {
	int pid;
	struct sigaction sa;

	pid = getpid();
	printf("[PID]: %d\n", pid);
	printf("Waiting for a message...\n");

	sa.sa_sigaction = ft_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO; // sa.sa_flags = 0じゃだめ？
	
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause();
	return 0;
}
