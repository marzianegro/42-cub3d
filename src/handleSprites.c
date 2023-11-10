/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleSprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:29 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/10 13:00:07 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_upload_sprites(t_game *game)
{
	game->tex.spt[0].img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->map.north, &game->tex.width, &game->tex.height);
	game->tex.spt[0].addr = mlx_get_data_addr(game->tex.spt[0].img,
			&game->tex.spt[0].bpp, &game->tex.spt[0].line_len,
			&game->tex.spt[0].endian);
	game->tex.spt[1].img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->map.south, &game->tex.width, &game->tex.height);
	game->tex.spt[1].addr = mlx_get_data_addr(game->tex.spt[1].img,
			&game->tex.spt[1].bpp, &game->tex.spt[1].line_len,
			&game->tex.spt[1].endian);
	game->tex.spt[2].img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->map.west, &game->tex.width, &game->tex.height);
	game->tex.spt[2].addr = mlx_get_data_addr(game->tex.spt[2].img,
			&game->tex.spt[2].bpp, &game->tex.spt[2].line_len,
			&game->tex.spt[2].endian);
	game->tex.spt[3].img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->map.east, &game->tex.width, &game->tex.height);
	game->tex.spt[3].addr = mlx_get_data_addr(game->tex.spt[3].img,
			&game->tex.spt[3].bpp, &game->tex.spt[3].line_len,
			&game->tex.spt[3].endian);
}

void	ft_unload_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->tex.spt[0].img);
	mlx_destroy_image(game->mlx_ptr, game->tex.spt[1].img);
	mlx_destroy_image(game->mlx_ptr, game->tex.spt[2].img);
	mlx_destroy_image(game->mlx_ptr, game->tex.spt[3].img);
}
