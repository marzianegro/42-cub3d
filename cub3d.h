/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:21:50 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/08 15:15:52 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* HEADER FILES */
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

/* MACROS */
# define SIZE 1000000
# define X 0
# define Y 1
# define Z 2
# define WIN_WIDTH
# define WIN_HEIGHT


# define UP_ARROW		65362
# define LEFT_ARROW		65361
# define RIGHT_ARROW	65363
# define DOWN_ARROW		65364

# define W_KEY		119
# define A_KEY		97
# define S_KEY		115
# define D_KEY		100
# define ESC_KEY	65307

/* STRUCTURES */

typedef	struct s_data
{
	void	*img;
	char	*addr;
	int		bpl; // bits-per-pixel
	int		line_len;
	int		endian;
}			t_data;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		player;
	int		ceiling;
	char	*north;
	char	*east
	char	*west;
	int		floor;
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
}			t_player;

typedef	struct s_ray
{
	// x coordinate of the camera plane that the current x coordinate of the screen represents
	double	camera_x;
	// direction in which the ray's going
	double	raydir_x;
	double	raydir_y;
	// current square of the map the ray is in
	double	map_x;
	double	map_y;
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
	t_data		*xpm;
	int			height;
	int			width;
	int			wall_height;
	int			wall_start;
	int			wall_end;
	double		wall_x;
	int			pos;
	double		coor_x;
	double		coor_y;
	// how much to increase the texture coordinate per screen pixel
	double		step;
}			t_texture;

typedef	struct s_time
{
	double	fps; // current frame
	double	old_fps; // previous frame
	double	frame_time;
	double	move_speed;
	double	rot_speed;
}			t_time;

typedef struct s_game
{
	t_map		map;
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		data;
	t_player	plyr;
	t_ray		ray;
	t_texture	tex;
	t_time		time;
}			t_game;

/* PROTOTYPES */
/* ft_checkMap.c */
void	ft_check_ext(char **av);
void	ft_floodfill(char **mapcopy, int x, int y);
void	ft_afterff(t_map *map, char **mapcopy);
void	ft_checkchecks(t_map *map);
/* ft_DDA.c */
/* ft_drawMap.c */
/* ft_handleEnds.c */
void	ft_error(char *str);
/* ft_initMap.c */
void	ft_init_map(t_game *game, char *av);
/* ft_initMLX.c */
void	ft_draw_map(t_map *map, t_game *game);
int		ft_keys(int key, t_game *game);
void	ft_hooks(t_game *game);
void	ft_mlxinit(t_map *map, t_game *game);
/* ft_initSprites.c */
void	*ft_create(t_game *game, char *xpm);
void	ft_upload_all(t_game *game);
/* ft_loopMap.c */
int		ft_redrawinloop(t_game *game);
/* ft_movePlayer.c */
void	ft_forward(t_game *game, t_map *map);
void	ft_left(t_game *game, t_map *map);
void	ft_backward(t_game *game, t_map *map);
void	ft_right(t_game *game, t_map *map);
/* ft_preDDA.c */
/* ft_rotPlane.c */
void	ft_rot_left(t_game *game);
void	ft_rot_right(t_game *game);
/* ft_termSprites.c */
void	ft_unload_all(t_game *game);

#endif
