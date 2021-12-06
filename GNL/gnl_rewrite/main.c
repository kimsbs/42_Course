#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char *gnl(int fd);

char *ft_strdup(char *S1);

int main(int argc, char **argv)
{
	int fd;
	char *tmp;

	tmp = NULL;
	if(argc < 2)
		return 0;
	fd = open(argv[1], O_RDONLY);
	while((tmp = gnl(fd)))
	{
		printf("[%s]\n",tmp);
		free(tmp);
	}
	system("leaks a");
}
