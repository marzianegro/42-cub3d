/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initSprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:29 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/08 15:15:45 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_create(t_game *game, char *xpm)
{
	int		width;
	int		height;
	void	*sprite;

	sprite = mlx_xpm_file_to_image(game->mlx_ptr, xpm, &width, &height);
	return (sprite);
}

void	ft_upload_all(t_game *game)
{
	// different uploading functions
}
