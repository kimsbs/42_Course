#include "../includes/so_long.h"

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
    t_game  game;

    if(argc != 2)
        exit_handler("Usage: ./so_long [MAP_FILE.ber]\n");
    map_init(argv[1], &game);
    mlx_ptr = mlx_init();

}