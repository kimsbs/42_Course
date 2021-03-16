#include "map.h"

void	stdinput(void)
{
	int fd;
	int n;
	char input[512];
	char *title;

	title = "stdin_map";
	fd = open(title, O_CREAT|O_TRUNC|O_WRONLY, 0600);
	n = read(0, input, 512);
	input[n-1] = '\0';
	print_str(input);
	/*
	while ( ( n = read(0, input, 512)) > 0)
	{
		//n = read(0, input, 512);
		write(fd, input, n);
		if(input[n - 1] == '\n')
			break;
	}
	doing(title);*/
}

void	doing(char *title)
{
	char *map = read_map(title);
	int line_cnt = infocheck(map);
	int hor_cnt = boxcheck(map, line_cnt);
	if(line_cnt < 0 || hor_cnt < 0)
		return ;
	make_strt(line_cnt, hor_cnt);
	init_strt(line_cnt, hor_cnt, map);
	g_x = 0;
	g_y = 0;
	g_MAX = 0;
	moving(line_cnt, hor_cnt);
	write(1, "\n", 1);
	free_strt(map, line_cnt);
}
