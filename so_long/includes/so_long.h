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
	void	*ptr;
	int		w;
	int		h;
}	t_img;

typedef struct s_links
{
	t_img	tree;
	t_img	tile;
	t_img	coin;
	t_img	exit;
	t_img	pu[3];
	t_img	pd[3];
	t_img	pl[2];
	t_img	pr[2];
	t_img	enemy[4];
}	t_links;

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*win;
	int		player_x;
	int		player_y;
	int		player_cnt;
	int		enemy_x;
	int		enemy_y;
	int		enemy_cnt;
	int		enemy_movement;
	int		coin_cnt;
	int		exit_cnt;
	int		height;
	int		width;
	int		animation;
	int		move_cnt;
	t_img	player;
	t_img	enemy;
	t_img	dummy;
	t_links	link;
}	t_game;

int		ft_strlen(const char *s);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
void	exit_handler(char *s1);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	read_map(int fd, t_game *game);
void	using_mlx(t_game *map);
void	print_map(t_game *game);
void	move_to_west(t_game *game);
void	move_to_east(t_game *game);
void	move_to_south(t_game *game);
void	move_to_north(t_game *game);
void	resource_init(t_game *game);
int		exit_game(t_game *game);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int num);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

#endif
