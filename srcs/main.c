#include "../includes/so_long.h"

int deal_key(int key, void *param)
{
	param = 0;
	ft_putchar(key);
	return (0);
}

void map_init(char *map_name, t_game *game)
{
    int fd;
    
    fd = open(map_name, O_RDONLY, 0600);
    if(fd <= 0)
        exit_handler("File open fail\n");
    read_map(fd, game);
}

int main(int argc, char **argv)
{
    void    *mlx_ptr;
	void	*win_ptr;
    t_game  game;

    if(argc != 2)
        exit_handler("Usage: ./so_long [MAP_FILE.ber]\n");
    map_init(argv[1], &game);
    mlx_ptr = mlx_init();
	printf("%d %d\n", game.height, game.width);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}
