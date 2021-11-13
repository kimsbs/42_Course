#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>

# define TILE_SIZE 71

typedef struct s_img
{
  void  *ptr;
  int   w;
  int   h;
} t_img;

typedef struct s_links
{
  t_img tree;
  t_img tile;
  t_img coin;
  t_img exit;
  t_img pu0;
  t_img pu1;
  t_img pu2;
  t_img pd0;
  t_img pd1;
  t_img pd2;
  t_img pl0;
  t_img pl1;
  t_img pr0;
  t_img pr1;
} t_links;

typedef struct s_game
{
    void   *mlx;
    void    *win;
    int     p[2];
    char    **map;
    int     player_cnt;
    int     coin_cnt;
    int     exit_cnt;
    int     height;
    int     width;
    t_img   dummy;
    t_links link;
}t_game;

typedef struct s_data
{
  void *img;
  char *addr;
  int bits_per_pixel;
  int line_length;
  int endian;
} t_data;

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
