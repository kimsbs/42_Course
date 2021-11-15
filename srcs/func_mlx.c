#include "../includes/so_long.h"

int deal_key(int key, t_game *game)
{
  if (key == 53)
  {
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
  }
  else if (key == 13 || key == 126)
    move_to_north(game);
  else if (key == 0 || key == 123)
    move_to_west(game);
  else if (key == 1 || key == 125)
    move_to_south(game);
  else if (key == 2 || key == 124)
    move_to_east(game);
  else
    ft_putchar(key);
  return (0);
}

int exit_with_mouse(t_game *game)
{
  mlx_destroy_window(game->mlx, game->win);
  exit(0);
  return (0);
}

int  looping(t_game *game)
{
  print_map(game, 1);
  print_map(game, 0);
  return (0);
}

void  using_mlx(t_game *game)
{
  game->mlx = mlx_init();
  game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height * TILE_SIZE, "So_long");
  img_init(game);
  mlx_key_hook(game->win, deal_key, game);
  mlx_hook(game->win, 17, 0, exit_with_mouse, game);
  mlx_loop_hook(game->mlx, &looping, game);
  mlx_loop(game->mlx);
}
