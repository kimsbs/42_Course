#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 10, 20, "hello");
    mlx_loop(mlx_ptr);
}