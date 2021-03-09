#include <stdio.h>
#include <stdlib.h>

void 	itoa(int sol, char *base_to, int size, char *str)
{
	int quotient;
	int remain;
	int b_len;
	int cnt;

	if(sol < 0)
		str[0] = '-';
	b_len = 0;
	while(base_to[b_len])
		b_len++;
	
	cnt = 0;
	quotient = sol;
	while(quotient)
	{
		remain = quotient % b_len;
		if(remain < 0)
			remain *= -1;
		str[size - cnt]	= base_to[remain];
		quotient /= b_len;
		cnt++;
	}
}

char	*ft_convert_base2(int sol, char *base_to)
{
	int b_len;
	int tmp;
	int size;
	char *str;

	b_len = 0;
	while(base_to[b_len])
		b_len++;
	if(b_len <= 1)
		return (0);
	tmp = sol;
	size = 0;
	while(tmp){
		size++;
		tmp /= b_len;
	}
	if(sol < 0)
		size++;
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	itoa(sol, base_to, size - 1, str);
	return (str);
}
int main()
{
	int sol;
	char base[3] = "01";
	char *tmp;
	scanf("%d", &sol);
	tmp = ft_convert_base2(sol, base);
	printf("%s", tmp);
}
