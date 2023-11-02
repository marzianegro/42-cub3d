/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleEnds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:31 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/02 12:14:37 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(char *str)
{
	printf("\033[1;91mError\033[0;39m: %s!\n", str);
	exit(EXIT_FAILURE);
}

char	*ft_free(char **buf)
{
	if (*buf)
	{
		free(*buf);
		*buf = NULL;
	}
	return (NULL);
}

void	ft_free_matrix(char **mtx)
{
	int	y;

	y = 0;
	if (mtx)
	{
		while (mtx[y])
		{
			ft_free(mtx[y]);
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
