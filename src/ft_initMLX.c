/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initMLX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:47:54 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/07 16:12:25 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_draw_map(t_map *map, t_game *game)
{
	ft_upload_all(game);
	ft_draw_sprites(map, game);
}

// to be adjusted
int	ft_keys(int key, t_game *game)
{
	if (key == ESC_KEY)
		ft_end(game, 1);
	else if (key == W_KEY || key == UP_ARROW)
		ft_up(game, &game->map);
	else if (key == A_KEY || key == LEFT_ARROW)
		ft_left(game, &game->map);
	else if (key == S_KEY || key == DOWN_ARROW)
		ft_down(game, &game->map);
	else if (key == D_KEY || key == RIGHT_ARROW)
		ft_right(game, &game->map);
	else
		return (1);
	return (0);
}

// to be adjusted
void	ft_hooks(t_game *game)
{
	mlx_hook(game->win_ptr, 17, 0, ft_end, game);
	mlx_hook(game->win_ptr, 02, 1L << 0, ft_keys, game);
}

void	ft_mlxinit(t_map *map, t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, map->width * 64,
			map->height * 64, "Get out of the maze!");
	ft_draw_map(map, game);
	ft_hooks(game);
	mlx_loop_hook(game->mlx_ptr, ft_redrawinloop, game);
	mlx_loop(game->mlx_ptr);
}
