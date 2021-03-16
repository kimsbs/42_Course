#ifndef MAP_H
# define MAP_H

char	*read_map(char *path);
char	*extract_element(char *map);
int		same_element(char *element);
int		infocheck(char *map);
int		in_element(char c, char *str);
int		horizontal_check(char *map);
int		boxcheck(char *map, int line_count);

char	*g_find;

#endif
