/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loopMap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:47 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/07 16:15:24 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// to be adjusted
int	ft_redrawinloop(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y] != NULL)
	{
		x = 0;
		while (x < game->map.width)
		{
			// redrawing functions
			x++;
		}
		y++;
	}
	return (0);
}
