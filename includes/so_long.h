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
    int     player_cnt;
    int     coin_cnt;
    int     exit_cnt;
    int     height;
    int     width;
}t_game;

typedef struct s_data
{
  void *img;
  char *addr;
  int bits_per_pixel;
  int line_length;
  int endian;
} t_data;

typedef struct s_ptr
{
  void *mlx;
  void *win;
} t_ptr;

void    exit_handler(char *s1);
void	ft_putchar(char c);
void	ft_putstr(char *s);
int	    ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int 	ft_strlcpy(char *dst, const char *src, int dstsize);
char   	*ft_strjoin(char const *s1, char const *s2);
char    **ft_split(char const *s, char c);
void    read_map(int fd, t_game *game);
void    using_mlx(t_game *map);

#endif
