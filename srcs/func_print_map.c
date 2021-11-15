#include "../includes/so_long.h"

static void  put_entity(t_game *game, int x, int y)
{
  if(game->map[y][x] == '1')
  {
    mlx_put_image_to_window(game->mlx, game->win, game->link.tree.ptr, x * TILE_SIZE, y * TILE_SIZE);   
  }  
  else
  {
    mlx_put_image_to_window(game->mlx, game->win, game->link.tile.ptr, x * TILE_SIZE, y * TILE_SIZE);  
  }
}

static void put_entity2(t_game *game, int x, int y)
{ 
  if(game->map[y][x] == 'e' && game->coin_cnt == 0 && game->exit_cnt == 1)
  {
    mlx_put_image_to_window(game->mlx, game->win, game->link.exit.ptr, x * TILE_SIZE, y * TILE_SIZE);   
  }  
  else if(game->map[y][x] == 'c')
  {
    mlx_put_image_to_window(game->mlx, game->win, game->link.coin.ptr, x * TILE_SIZE, y * TILE_SIZE);  
  }
  mlx_put_image_to_window(game->mlx, game->win, game->player.ptr, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}

void  print_map(t_game *game, int flag)
{
  int x;
  int y;

  y = -1;
  while(++y < game->height)
  {
    x = -1;
    while(++x < game->width)
    {
      if(flag)
        put_entity(game, x, y);
      else
        put_entity2(game, x, y);
    }
  }
}

