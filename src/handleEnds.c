/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleEnds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:31 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/24 18:03:06 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(char *str)
{
	printf("\033[1;91mError\033[0;39m: %s!\n", str);
	exit(EXIT_FAILURE);
}

void	ft_free_map(t_game *game)
{
	int	str;

	str = 0;
	while (game && str < game->map.row)
	{
		if (game->map.map[str])
			free(game->map.map[str++]);
	}
	if (game && game->map.map)
		free(game->map.map);
}

void	ft_free_matrix(char **mtx)
{
	int	y;

	y = 0;
	if (mtx)
	{
		while (mtx[y])
		{
			free(mtx[y]);
			y++;
		}
		free(mtx);
	}
}

int	ft_end(t_game *game)
{
	//ft_unload(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	ft_free_matrix(game->map.map);
	free(game->mlx_ptr);
	exit(0);
}

