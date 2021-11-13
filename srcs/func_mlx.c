#include "../includes/so_long.h"

int deal_key(int key, t_ptr *mlx)
{
  if (key == 53)
  {
    mlx_destroy_window(mlx->mlx, mlx->win);
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

int exit_with_mouse(t_ptr *mlx)
{
  mlx_destroy_window(mlx->mlx, mlx->win);
  exit(0);
  return (0);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
  char *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int *)dst = color;
}

void  using_mlx(t_game *map)
{
  t_ptr  mlx;
  t_data img;

  mlx.mlx = mlx_init();
  mlx.win = mlx_new_window(mlx.mlx, map->width * 40, map->height * 40, "So_long");
  img.img = mlx_new_image(mlx.mlx, map->width * 40, map->height * 40);
  img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
  for (int i = 0; i < map->width * 40; i++)
  {
    for (int j = 0; j < map->height * 40; j++)
    {
      mlx_pixel_put(mlx.mlx, mlx.win, i, j, 0x00FFFFFF);
    }
  }
  //mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
  mlx_key_hook(mlx.win, deal_key, &mlx);
  mlx_hook(mlx.win, 17, 0, exit_with_mouse, &mlx);
  mlx_loop(mlx.mlx);
}