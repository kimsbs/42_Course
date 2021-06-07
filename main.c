#include "ft_printf.h"
#include <stdio.h>
int main()
{
	int res1, res2;
	int *p, a;

	a = 124;
	p = &a;
	res1 = ft_printf("[%2.9p]", 1234);
	printf("\n");
	res2 = printf("[%2.9p]", 1234);
	printf("\n%d %d\n", res1, res2);
}
