/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initSprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:29 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/12 14:42:30 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_upload_sprites(t_game *game)
{
	game->data.img = ft_calloc(sizeof(t_data), 1);
	game->tex.spt[0].img = mlx_spt_file_to_image(game->mlx_ptr, "path", &game->tex.width, &game->tex.height)
	game->tex.spt[0].addr = mlx_get_data_addr(game->tex.spt[0].img, &game->tex.spt[0].bpp, &game->tex.spt[0].line_len, &game->tex.spt[0].endian);
}
