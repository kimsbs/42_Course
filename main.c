#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd;
	char *sol;

	fd = open("test", O_RDONLY);
	if(fd <= 0)
	{
		printf("open error!\n");
		return (0);
	}
	while(get_next_line(fd, &sol) > 0)
	{
		//printf("%s\n", sol);
		free(sol);
	}
	system("Leaks a");
}
