#include "../includes/so_long.h"

static void get_size(t_game *game)
{
    game->height = -1;
    game->width = ft_strlen(game->map[0]);
    while (game->map[++game->height])
    {
        if(game->width != ft_strlen(game->map[game->height]))
            exit_handler("Map is not rectangular\n");
    }
}

static void is_blocked(t_game *game)
{
    int x;
    int y;

    y = -1;
    while (++y < game->height)
    {
        if (y == 0 || y == game->height - 1)
        {
            x = -1;
            while (++x < game->width)
            {
                if (game->map[y][x] != '1')
                    exit_handler("Map is not closed\n");
            }
        }
        else
        {
            if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
                exit_handler("Map is not closed\n");
        }
    }
}

static void var_is_ok(t_game *game)
{
    int x;
    int y;

    game->coin = 0;
    game->exit = 0;
    y = -1;
    while (++y < game->height)
    {
        x = -1;
        while (++x < game->width)
        {
            if (game->map[y][x] == 'p')
            {
                game->p[0] = x;
                game->p[1] = y;
            }
            else if (game->map[y][x] == 'c')
                game->coin++;
            else if (game->map[y][x] == 'e')
                game->exit++;
            else if (game->map[y][x] != '1' && game->map[y][x] != '0')
                exit_handler("Map have more than 5 characters\n");
        }
    }
    if (game->coin < 0 || game->exit != 1 || (game->p[0] <= 0 || game->p[0] >= game->width) || (game->p[1] <= 0 || game->p[1] >= game->height))
        exit_handler("Map char error\n");
}

void    read_map(int fd, t_game *game)
{
    int len;
    char str[257];
    char *tmp;

    tmp = NULL;
    len = read(fd, &str, 256);
    while (len > 0)
    {
        str[len] = '\0';
        tmp = ft_strjoin(tmp, str);
        len = read(fd, &str, 256);
    }
    if (!tmp)
            exit_handler("Map doesn't exist\n");
    game->map = ft_split(tmp, '\n');
    free(tmp);
    get_size(game);
    is_blocked(game);
    var_is_ok(game);
}