#ifndef MAP_H
# define MAP_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>


int		g_x;
int		g_y;
int		g_MAX;
char    *g_find;
typedef struct  s_matrix{
                int *depth;
                char *data;
}               t_matrix;
t_matrix        *g_matrix;

void	print_str(char *str);
void	print_all(int size);
void	fill(void);
void	make_matrix(int line, int hor);
void	init_matrix(int line, int hor, char *map);
void	free_matrix(char *map, int line);
void    solve(int x, int y, int i, int j);
void	last(int x, int y, int i);
int     adder(int x, int y);
int     min_num(int a, int b, int c);

char	*read_map(char *path);
char	*extract_element(char *map);
int		same_element(char *element);
int		infocheck(char *map);
int		in_element(char c, char *str);
int		horizontal_check(char *map);
int		boxcheck(char *map, int line_count);

void	stdinput(void);
void	doing(char *title);

#endif
