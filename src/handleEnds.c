/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleEnds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <mnegro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:31 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/15 20:36:25 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(t_game *ptr, char *str, char *line)
{
	static t_game	*game;

	if (ptr)
		game = ptr;
	else
	{
		get_next_line(-42);
		ft_free((void **)&game->map.north);
		ft_free((void **)&game->map.south);
		ft_free((void **)&game->map.east);
		ft_free((void **)&game->map.west);
		if (game->map.map)
			ft_free_matrix(game->map.map);
		if (line)
			ft_free((void **)&line);
		printf("\033[1;91mError\033[0;39m: %s!\n", str);
		exit(EXIT_FAILURE);
	}
}

void	ft_error_cf(t_game *ptr, char *str, char *line, char **rgb)
{
	static t_game	*game;

	if (ptr)
		game = ptr;
	else
	{
		get_next_line(-42);
		ft_free((void **)&game->map.north);
		ft_free((void **)&game->map.south);
		ft_free((void **)&game->map.east);
		ft_free((void **)&game->map.west);
		ft_free((void **)&line);
		ft_free_matrix(rgb);
		printf("\033[1;91mError\033[0;39m: %s!\n", str);
		exit(EXIT_FAILURE);
	}
}

void	ft_init_err(t_game *game)
{
	ft_error(game, NULL, NULL);
	ft_error_cf(game, NULL, NULL, NULL);
}

int	ft_end(t_game *game)
{
	get_next_line(-42);
	if (game->map.map)
		ft_free_matrix(game->map.map);
	ft_free((void **)&game->map.north);
	ft_free((void **)&game->map.south);
	ft_free((void **)&game->map.east);
	ft_free((void **)&game->map.west);
	ft_unload_sprites(game);
	if (game->data.img)
		mlx_destroy_image(game->mlx_ptr, game->data.img);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}
