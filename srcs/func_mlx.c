#include "../includes/so_long.h"

int deal_key(int key, t_game *game)
{
  if (key == 53)
  {
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
  }
  else if (key == 13 || key == 126)
    write(1, "w", 1);
  else if (key == 0 || key == 123)
    write(1, "a", 1);
  else if (key == 1 || key == 125)
    write(1, "s", 1);
  else if (key == 2 || key == 124)
    write(1, "d", 1);
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

void	ft_put_img64(t_game *game, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img_ptr, y * 40, x * 40);
}

void *get_xpm_ptr(t_game *game, char *str)
{
  void *img;
  img = mlx_xpm_file_to_image(game->mlx, str, &(game->dummy.w), &(game->dummy.h)); 
  if(!img)
    exit_handler("xpm error\n");
  return (img);
}

void  img_init(t_game *game)
{
  game->link.coin.ptr = get_xpm_ptr(game, "./img/coin.xpm");
  game->link.exit.ptr = get_xpm_ptr(game, "./img/exit.xpm");
  game->link.tile.ptr = get_xpm_ptr(game, "./img/tile.xpm");
  game->link.tree.ptr = get_xpm_ptr(game, "./img/tree.xpm");
  game->link.pd0.ptr = get_xpm_ptr(game, "./img/pd0.xpm");
  game->link.pd1.ptr = get_xpm_ptr(game, "./img/pd1.xpm");
  game->link.pd2.ptr = get_xpm_ptr(game, "./img/pd2.xpm");
  game->link.pu0.ptr = get_xpm_ptr(game, "./img/pu0.xpm");
  game->link.pu1.ptr = get_xpm_ptr(game, "./img/pu1.xpm");
  game->link.pu2.ptr = get_xpm_ptr(game, "./img/pu2.xpm");
  game->link.pl0.ptr = get_xpm_ptr(game, "./img/pl0.xpm");
  game->link.pl1.ptr = get_xpm_ptr(game, "./img/pl1.xpm");
  game->link.pr0.ptr = get_xpm_ptr(game, "./img/pr0.xpm");
  game->link.pr1.ptr = get_xpm_ptr(game, "./img/pr1.xpm");
}

void  put_entity(t_game *game, int x, int y)
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

void  print_map(t_game *game)
{
  int x;
  int y;

  y = -1;
  while(++y < game->height)
  {
    x = -1;
    while(++x < game->width)
    {
      put_entity(game, x, y);
    }
  }
}

void  using_mlx(t_game *game)
{

  game->mlx = mlx_init();
  game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height * TILE_SIZE, "So_long");
  img_init(game);
  print_map(game);
  mlx_key_hook(game->win, deal_key, game);
  mlx_hook(game->win, 17, 0, exit_with_mouse, game);
  mlx_loop(game->mlx);
}
