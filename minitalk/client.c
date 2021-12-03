#include "minitalk.h"

int	g_flag;

long	ft_atoi(const char *str)
{
	long	sol;
	int		min;
	char	*tmp;

	tmp = (char *)str;
	sol = 0;
	min = 1;
	if (*tmp == '-')
	{
		min = -1;
		tmp++;
	}
	while (*tmp >= '0' && *tmp <= '9')
	{
		sol = (sol * 10) + (min * (*tmp - '0'));
		tmp++;
	}
	return (sol);
}

void	send_msg(int pid, char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		usleep(10);
		g_flag = 0;
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_flag)
		{
		}
	}
}

void	receive(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "done!\n", 6);
		exit(0);
	}
	else
		g_flag = 1;
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act_r;

	act_r.sa_handler = receive;
	if (argc != 3)
		exit(0);
	if (sigaction(SIGUSR1, &act_r, NULL) || sigaction(SIGUSR2, &act_r, NULL))
	{
		write(1, "Signal Error\n", 12);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	while (*argv[2])
		send_msg(pid, *(argv[2])++);
	send_msg(pid, *argv[2]);
}
