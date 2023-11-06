/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleEnds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:31 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/06 16:01:09 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(char *str)
{
	printf("\033[1;91mError\033[0;39m: %s!\n", str);
	exit(EXIT_FAILURE);
}

void	ft_exit(t_game *game, char *str)
{
	printf("\033[1;91mError\033[0;39m: %s!\n", str);
	ft_free_matrix(game->map.map);
	exit(EXIT_FAILURE);
}

void	ft_free_matrix(char **mtx)
{
	int	y;

	y = 0;
	if (mtx)
	{
		while (mtx[y])
		{
			ft_free(&mtx[y]);
			y++;
		}
		ft_free(mtx);
	}
}

int	ft_end(t_game *game)
{
	ft_unload(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	ft_free_matrix(game->map.map);
	ft_free(game->mlx_ptr);
	exit(0);
}
