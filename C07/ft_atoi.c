#include <stdio.h>
#include <unistd.h>

int base_check(char *base)
{
	int i;
	int j;

	if(!base)
		return (0);
	i = 0;
	while (base[i])
	{
		if(base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while(j < i)
		{
			if(base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int find_base(char c, char *base)
{
	int i;
	
	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return i;
		i++;
	}
	return (-1);
}
int possible(char c, char *base)
{
	if (c == '+' || c == '-')
		return (1);
	else if (find_base(c, base) != -1)
		return (2);
	else if (c == ' ' || c == '	' || c == '\n')
		return (1);
	else
		return (0);
}
int make_int(char *nbr, int cnt, char *base, int b_len)
{
	int len;
	int i;
	int tmp;
	int sol;
	int tmp2;

	len = 0;
	sol = 0;
	while (possible(nbr[len], base) == 2)
		len++;
		i = -1;
	while (++i < len)
	{
		tmp2 = len - i;													tmp = 1;
		if (cnt % 2 != 0)
			tmp = -1;
		tmp *= find_base(nbr[i], base);
		while (--tmp2)
			tmp *= b_len;
		sol += tmp;
	}
	return (sol);
}

int ft_atoi(char *nbr)
{
	int cnt;
	int b_len;
	char *base_from;

	base_from = "0123456789";
	cnt = 0;
	b_len = 0;
	while (base_from[b_len])
		b_len++;
	while (*nbr)
	{
		if (possible(*nbr, base_from))
		{
			if (*nbr == '-')
				cnt++;
			else if (find_base(*nbr, base_from) != -1)
				return (make_int(nbr, cnt, base_from, b_len));							}
		else
			break;													nbr++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	char base[11] = "01";
	char base2[11] = "0123456789";
	printf("%d\n", ft_atoi(argv[1]));
}
