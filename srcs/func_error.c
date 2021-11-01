#include "../includes/so_long.h"

void exit_handler(char *s1)
{
	ft_putstr(s1);
	exit(-1);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	int len;
	int move;

	move = -1;
	len = ft_strlen(s);
	while(++move < len)
	{
		ft_putchar(s[move]);
	}
}
