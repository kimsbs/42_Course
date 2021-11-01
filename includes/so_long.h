#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_game{
    int     p[2];
    char    **map;
    int     height;
    int     width;
    int     coin;
    int     exit;
}t_game;

void    exit_handler(char *s1);
void	ft_putchar(char c);
void	ft_putstr(char *s);
int	    ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int 	ft_strlcpy(char *dst, const char *src, int dstsize);
char   	*ft_strjoin(char const *s1, char const *s2);
char    **ft_split(char const *s, char c);
void    read_map(int fd, t_game *game);

#endif
