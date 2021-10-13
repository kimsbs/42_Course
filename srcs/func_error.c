#include "../includes/so_long.h"

void exit_handler(char *s1)
{
	int len;

	len = ft_strlen(s1);
	write(1 , s1, len);
	exit(-1);
}