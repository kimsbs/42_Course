#include "minitalk_bonus.h"

void	print_num(int num)
{
	char	tmp;

	if (num / 10)
		print_num(num / 10);
	num %= 10;
	tmp = num + '0';
	write(1, &tmp, 1);
}

void	msg(char *s, int pid)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
	if (pid)
		print_num(pid);
	write(1, "\n", 1);
}

void	sig_handler(int sig, siginfo_t *sigi, void *context)
{
	static int	data;
	static int	bit;

	(void)context;
	if (!sigi->si_pid)
		return ;
	if (sig == SIGUSR1)
		data |= (1 << bit);
	if (++bit == 8)
	{
		if (data)
			write(1, &data, 1);
		else
			kill(sigi->si_pid, SIGUSR1);
		data = 0;
		bit = 0;
	}
	kill(sigi->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	act;

	msg("Server PID : ", getpid());
	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) || sigaction(SIGUSR2, &act, NULL))
	{
		msg("Signal Error", 0);
		exit(1);
	}
	while (1)
		pause();
}
