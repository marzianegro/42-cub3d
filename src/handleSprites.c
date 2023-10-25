/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleSprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:29 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/25 17:29:36 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_upload(t_game *game)
{
	game->data.img = ft_calloc(sizeof(t_data), 1);
	game->tex.spt[0].img = mlx_xpm_file_to_image(game->mlx_ptr,
			"../spt/northtree", &game->tex.width, &game->tex.height);
	game->tex.spt[0].addr = mlx_get_data_addr(game->tex.spt[0].img,
			&game->tex.spt[0].bpp, &game->tex.spt[0].line_len,
			&game->tex.spt[0].endian);
	game->data.img = ft_calloc(sizeof(t_data), 1);
	game->tex.spt[1].img = mlx_xpm_file_to_image(game->mlx_ptr,
			"../spt/southtree", &game->tex.width, &game->tex.height);
	game->tex.spt[1].addr = mlx_get_data_addr(game->tex.spt[1].img,
			&game->tex.spt[1].bpp, &game->tex.spt[1].line_len,
			&game->tex.spt[1].endian);
	game->data.img = ft_calloc(sizeof(t_data), 1);
	game->tex.spt[2].img = mlx_xpm_file_to_image(game->mlx_ptr,
			"../spt/easttree", &game->tex.width, &game->tex.height);
	game->tex.spt[2].addr = mlx_get_data_addr(game->tex.spt[2].img,
			&game->tex.spt[2].bpp, &game->tex.spt[2].line_len,
			&game->tex.spt[2].endian);
	game->data.img = ft_calloc(sizeof(t_data), 1);
	game->tex.spt[3].img = mlx_xpm_file_to_image(game->mlx_ptr,
			"../spt/westtree", &game->tex.width, &game->tex.height);
	game->tex.spt[3].addr = mlx_get_data_addr(game->tex.spt[3].img,
			&game->tex.spt[3].bpp, &game->tex.spt[3].line_len,
			&game->tex.spt[3].endian);
}

void	ft_unload(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->tex.spt[0].img);
	mlx_destroy_image(game->mlx_ptr, game->tex.spt[1].img);
	mlx_destroy_image(game->mlx_ptr, game->tex.spt[2].img);
	mlx_destroy_image(game->mlx_ptr, game->tex.spt[3].img);
}
