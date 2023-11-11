/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleEnds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:31 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/11 14:02:57 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(char *str)
{
	printf("\033[1;91mError\033[0;39m: %s!\n", str);
	exit(EXIT_FAILURE);
}

void	ft_error_line(char *str, char *line)
{
	printf("\033[1;91mError\033[0;39m: %s!\n", str);
	if (line)
		ft_free(&line);
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

void	ft_exit(t_game *game, char *str)
{
	printf("\033[1;91mError\033[0;39m: %s!\n", str);
	ft_free(game->tex.spt);
	if (game->map.map)
		ft_free_matrix(game->map.map);
	exit(EXIT_FAILURE);
}

int	ft_end(t_game *game)
{
	if (game->map.map)
		ft_free_matrix(game->map.map);
	ft_unload_sprites(game);
	ft_free(game->tex.spt);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	ft_free(game->mlx_ptr);
	exit(0);
}
