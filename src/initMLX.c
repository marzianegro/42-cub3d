/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMLX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:47:54 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/15 15:57:16 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_mlx_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT, "Welcome to cub3d!");
	game->data.img = NULL;
}

int	ft_keys(int key, t_game *game)
{
	if (key == ESC_KEY)
		ft_end(game);
	else if (key == W_KEY)
		ft_forward(game, &game->map);
	else if (key == A_KEY)
		ft_left(game, &game->map);
	else if (key == S_KEY)
		ft_backward(game, &game->map);
	else if (key == D_KEY)
		ft_right(game, &game->map);
	else if (key == RIGHT_ARROW)
		ft_rot_right(game);
	else if (key == LEFT_ARROW)
		ft_rot_left(game);
	else
		return (1);
	return (0);
}

void	ft_hooks(t_game *game)
{
	mlx_hook(game->win_ptr, 17, 0, ft_end, game);
	mlx_hook(game->win_ptr, 02, 1L << 0, ft_keys, game);
}

void	ft_mlx_start(t_game *game)
{
	ft_upload_sprites(game);
	ft_calc_cf_color(game);
	ft_init_plyr(&game->map, &game->plyr);
	ft_hooks(game);
	mlx_loop_hook(game->mlx_ptr, ft_redrawinloop, game);
	mlx_loop(game->mlx_ptr);
}
