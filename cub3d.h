/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:21:50 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/12 15:17:49 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* HEADER FILES */
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>

/* MACROS */
# define SIZE 1000000
# define SCREEN_WIDTH 900
# define SCREEN_HEIGHT 900

# define LEFT_ARROW		65361
# define RIGHT_ARROW	65363
# define W_KEY		119
# define A_KEY		97
# define S_KEY		115
# define D_KEY		100
# define ESC_KEY	65307

# define PLAYER	'P'
# define X	1
# define Y	0
# define WALL	1

/* STRUCTURES */

typedef	struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_data;

typedef struct s_map
{
	char	**map;
	int		row;
	int		col;
	int		width;
	int		height;
	int		player[2];
	int		ceiling;
	int		floor;
	char	*north;
	char	*east;
	char	*west;
	char	*south;
}			t_map;

typedef	struct s_player
{
	// position of the player
	double	pos_x;
	double	pos_y;
	// direction in which the player's going
	double	dir_x;
	double	dir_y;
	// camera plane of the player
	double	plane_x;
	double	plane_y;
	// what direction to step in?
	int		step_x; // +1
	int		step_y; // -1
	double	move_speed;
	double	rot_speed;
}			t_player;

typedef	struct s_ray
{
	// x coordinate of the camera plane that the current x coordinate of the screen represents
	double	camera_x;
	// direction in which the ray's going
	double	dir_x;
	double	dir_y;
	// current square of the map the ray is in
	double	pos_x;
	double	pos_y;
	// lenght of the ray from the current position to the first x and y side
	double	sidedist_x;
	double	sidedist_y;
	// lenght of the ray from one x or y side to the next x or y side
	double	deltadist_x;
	double	deltadist_y;
	// pependicular distance used to calculate the length of the ray
	double	perpwalldist;
	// did the ray hit a wall?
	int		hit_wall;
	// did they ray hit the x side or y side of the wall?
	int		side_wall;
}			t_ray;

typedef	struct s_texture
{
	t_data		*spt;
	// which texure out of spt we're using
	int		num;
	int		height;
	int		width;
	int		wall_height;
	int		wall_start;
	int		wall_end;
	double	wall_x;
	int		pos;
	double	x_coor;
	double	y_coor;
	// how much to increase the texture coordinate per screen pixel
	double	step;
	int		**cf_rgb;
}			t_texture;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		data;
	t_map		map;
	t_player	plyr;
	t_ray		ray;
	t_texture	tex;
}			t_game;

/* PROTOTYPES */
/* calcMap.c */
bool	ft_cf_deets(char *line, t_texture *tex);
void	ft_perpwalldist(t_ray *ray);
void	ft_wall_deets(t_map *map, t_player *plyr, t_ray *ray, t_texture *tex);
void	ft_calc_wall(t_game *game);
/* checkMap.c */
void	ft_check_ext(char **av);
char	**ft_mtxdup(t_map *map);
void	ft_floodfill(char **mapcopy, int x, int y);
void	ft_afterff(t_map *map, char **mapcopy);
void	ft_check_map(t_map *map);
/* checkMap_bis.c */
void	ft_check_components(t_map *map);
void	ft_check_columns(t_map *map);
void	ft_check_rows(t_map *map);
/* DDA.c */
void	ft_dda(t_map *map, t_player *plyr, t_ray *ray);
/* drawMap.c */
void    ft_pixel_put(t_data *data, int x, int y, int color);
void    ft_draw_cf(t_game *game);
void	ft_draw_wall(t_game *game, int x);
/* handleEnds.c */
int		ft_end(t_game *game);
void	ft_error(char *str);
void	ft_free_map(t_game *game);
void	ft_free_matrix(char **mtx);
/* initDDA.c */
void	ft_init_plyr(t_map *map, t_player *plyr, t_ray *ray, int x);
void	ft_init_ray(t_player *plyr, t_ray *ray);
void	ft_deltadist(t_ray *ray);
void	ft_step_sidedist(t_player *plyr, t_ray *ray);
void	ft_init_dda(t_game *game, int x);
/* initMap.c */
void	ft_init_map(t_game *game, t_map *map, char *av);
/* initMLX.c */
void	ft_draw_map(t_map *map, t_game *game);
int		ft_keys(int key, t_game *game);
void	ft_hooks(t_game *game);
void	ft_mlxinit(t_game *game, t_map *map);
/* initSprites.c */
void	ft_upload_sprites(t_game *game);
/* loopMap.c */
int		ft_redrawinloop(t_game *game);
/* main.c */
/* movePlayer.c */
void	ft_forward(t_game *game, t_map *map);
void	ft_left(t_game *game, t_map *map);
void	ft_backward(t_game *game, t_map *map);
void	ft_right(t_game *game, t_map *map);
/* rotPlane.c */
void	ft_rot_left(t_game *game);
void	ft_rot_right(t_game *game);
/* termSprites.c */
void	ft_unload_all(t_game *game);

#endif
