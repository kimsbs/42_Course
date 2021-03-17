/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:28:44 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/17 22:07:08 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# define ERR_MSG "map error\n"
# define ERR_SIZE 10

int				g_x;
int				g_y;
int				g_max;
char			*g_find;

typedef struct	s_matrix
{
	int			*depth;
	char		*data;
}				t_matrix;
t_matrix		*g_matrix;

void			print_str(char *str);
void			print_all(int size);
void			fill(void);
void			make_matrix(int line, int hor);
void			init_matrix(int line, int hor, char *map);
void			free_matrix(char *map, int line);
void			solve(int x, int y, int i, int j);
void			last(int x, int y, int i);
int				adder(int x, int y);
int				min_num(int a, int b, int c);

char			*read_map(char *path);
char			*extract_element(char *map);
int				same_element(char *element);
int				infocheck(char *map);
int				in_element(char c, char *str);
int				horizontal_check(char *map);
int				boxcheck(char *map, int line_count, int i);

void			whole_matrix(int line_cnt, int hor_cnt, char *map);
void			stdinput(void);
void			doing(char *title, int line_cnt, int hor_cnt);

#endif
