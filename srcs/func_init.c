/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:50:55 by seungyki          #+#    #+#             */
/*   Updated: 2021/11/16 17:50:57 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_xpm_ptr(t_game *game, t_img *img, char *str)
{
	img->ptr = NULL;
	img->ptr = mlx_xpm_file_to_image(game->mlx, str,
			&(img->w), &(img->h));
	if (!img->ptr)
		exit_handler("xpm error\n");
}

void	img_init(t_game *game)
{
	get_xpm_ptr(game, &(game->link.coin), "./img/coin.xpm");
	get_xpm_ptr(game, &(game->link.exit), "./img/exit.xpm");
	get_xpm_ptr(game, &(game->link.tile), "./img/tile.xpm");
	get_xpm_ptr(game, &(game->link.tree), "./img/tree.xpm");
	get_xpm_ptr(game, &(game->link.pd[0]), "./img/pd0.xpm");
	get_xpm_ptr(game, &(game->link.pd[1]), "./img/pd1.xpm");
	get_xpm_ptr(game, &(game->link.pd[2]), "./img/pd2.xpm");
	get_xpm_ptr(game, &(game->link.pu[0]), "./img/pu0.xpm");
	get_xpm_ptr(game, &(game->link.pu[1]), "./img/pu1.xpm");
	get_xpm_ptr(game, &(game->link.pu[2]), "./img/pu2.xpm");
	get_xpm_ptr(game, &(game->link.pl[0]), "./img/pl0.xpm");
	get_xpm_ptr(game, &(game->link.pl[1]), "./img/pl1.xpm");
	get_xpm_ptr(game, &(game->link.pr[0]), "./img/pr0.xpm");
	get_xpm_ptr(game, &(game->link.pr[1]), "./img/pr1.xpm");
	game->player = game->link.pd[1];
}

void	enemy_init(t_game *game)
{
	get_xpm_ptr(game, &(game->link.enemy[0]), "./img/e_d.xpm");
	get_xpm_ptr(game, &(game->link.enemy[1]), "./img/e_l.xpm");
	get_xpm_ptr(game, &(game->link.enemy[2]), "./img/e_u.xpm");
	get_xpm_ptr(game, &(game->link.enemy[3]), "./img/e_r.xpm");
	game->enemy.ptr = game->link.enemy[0].ptr;
}

void	resource_init(t_game *game)
{
	img_init(game);
	enemy_init(game);
}
