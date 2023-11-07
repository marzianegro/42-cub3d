/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:00:26 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/07 15:26:25 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* All of this is done after the DDA has ended, because we have to calculate
	the distance of the ray from the wall, so that we can then calculate how
	high we have to draw the wall */
bool	ft_cf_deets(char *line, t_texture *tex)
{
	int		i;
	int		j;
	char	**rgb[2];

	i = -1;
	j = 0;
	if (ft_strchr(line, 'F'))
		i = 0;
	else if (ft_strchr(line, 'C'))
		i = 1;
	else
		return (false);
	rgb[i] = ft_split(&line[1], ',');
	while (rgb[i][j])
	{
		rgb[i][j] = ft_freetrim(rgb[i][j], ' ');
		if (ft_isloopdigit(rgb[i][j]))
			if (rgb[i][2][ft_strlen(rgb[i][2]) - 1] != '\n')
				return (false);
		tex->cf_rgb[i][j] = ft_atoi(rgb[i][j]);
		if (j++ > 3)
			return (false);
	}
	return (true);
}

/* We don't use the Euclidean distance from the point representing the player,
	but the distance from the camera plane (or the distance from the point,
	projected in the camera direction, to the player), to avoid the fish-eye
	effect, which would make all the walls become rounded and make us sick
	if we rotated. It’s also easier to calculate this perpendicular distance
	rather than the real distance, because we don’t even need to know the
	exact location where the wall was hit */
void	ft_perpwalldist(t_ray *ray)
{
	if (ray->side_wall == 0)
		ray->perpwalldist = ray->sidedist_x - ray->deltadist_x;
	else
		ray->perpwalldist = ray->sidedist_y - ray->deltadist_y;
}

void	ft_wall_deets(t_map *map, t_player *plyr, t_ray *ray, t_texture *tex)
{
	(void)map;
	tex->wall_height = (int)(SCREEN_HEIGHT / ray->perpwalldist);
	tex->wall_start = -tex->wall_height / 2 + SCREEN_HEIGHT / 2;
	if (tex->wall_start < 0)
		tex->wall_start = 0;
	tex->wall_end = tex->wall_height / 2 + SCREEN_HEIGHT / 2;
	if (tex->wall_end >= SCREEN_HEIGHT)
		tex->wall_end = SCREEN_HEIGHT - 1;
	if (ray->side_wall == 0)
		tex->wall_x = plyr->pos_y + ray->perpwalldist * ray->dir_y;
	else
		tex->wall_x = plyr->pos_x + ray->perpwalldist * ray->dir_x;
	tex->wall_x -= floor((tex->wall_x));
	tex->x_coor = (int)(tex->wall_x * (double)(tex->width));
	if (ray->side_wall == 0 && (ray->dir_x > 0
			|| ray->side_wall == 1) && ray->dir_y < 0)
		tex->x_coor = tex->width - tex->x_coor - 1;
}

void	ft_calc_wall(t_game *game)
{
	ft_perpwalldist(&game->ray);
	ft_wall_deets(&game->map, &game->plyr, &game->ray, &game->tex);
}
