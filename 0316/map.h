#ifndef MAP_H
# define MAP_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define Big(x ,y) ((x > y) ? (x) : (y))
#define Small(x, y) ((x > y) ? (y) : (x))

int		g_x;
int		g_y;
int		g_MAX;
char	**strt;

void	print_str(char *str);
void	print_all(char **str, int size);
void	fill(void);
int		possible(int i, int x, int y);
void	checker(int x, int y, int l_x, int l_y);
void	moving(int x, int y);
void	make_strt(int line, int hor);
void		init_strt(int line, int hor, char *map);
void	free_strt(char *map, int line);

char	*read_map(char *path);
char	*extract_element(char *map);
int		same_element(char *element);
int		infocheck(char *map);
int		in_element(char c, char *str);
int		horizontal_check(char *map);
int		boxcheck(char *map, int line_count);

void	stdinput(void);
void	doing(char *title);

char	*g_find;

#endif
