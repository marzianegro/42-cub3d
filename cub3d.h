/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:21:50 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/10 12:37:39 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* HEADER FILES */
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

/* MACROS */
# define SIZE 1000000
# define SCREEN_WIDTH 500
# define SCREEN_HEIGHT 500

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

/* STRUCTURES */

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_data;

typedef struct s_map
{
	char			**map;
	int				row;
	int				player[2];
	unsigned long	ceiling;
	unsigned long	floor;
	char			*north;
	char			*east;
	char			*west;
	char			*south;
}			t_map;

typedef struct s_player
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

typedef struct s_ray
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

typedef struct s_texture
{
	t_data		*spt;
	int			num;
	int			height;
	int			width;
	int			wall_height;
	int			wall_start;
	int			wall_end;
	double		wall_x;
	double		pos;
	double		x_coor;
	double		y_coor;
	// how much to increase the texture coordinate per screen pixel
	double		step;
	int			cf_rgb[2][3];
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
void	ft_wall_deets(t_player *plyr, t_ray *ray, t_texture *tex);
void	ft_calc_wall(t_game *game);
/* calcMapUtils.c */
char	*ft_freetrim(char *s1, const char del);
int		ft_isloopdigit(char *s);
/* checkMap.c */
void	ft_floodfill(t_game *game, t_map *map, int x, int y);
void	ft_check_map(t_game *game, t_map *map);
/* checkMapBis.c */
void	ft_check_ext(char **av);
void	ft_check_elems(t_game *game, t_map *map);
void	ft_check_elems_bis(t_game *game, t_map *map);
/* checkMapTris.c */
int		ft_check_coor(char *str);
void	ft_save_path(char *line, char **path);
bool	ft_init_textures(t_map *map, char *line);
void	ft_check_textures(t_game *game, t_map *map);
/* DDA.c */
void	ft_dda(t_map *map, t_player *plyr, t_ray *ray, t_texture *tex);
/* drawMap.c */
void	ft_pixel_put(t_data *data, int x, int y, int color);
void	ft_calc_cf_color(t_game *game);
int		ft_calc_tex_color(t_texture *tex);
void	ft_draw_cf(t_game *game);
void	ft_draw_wall(t_game *game, int x);
/* handleEnds.c */
void	ft_error(char *str);
void	ft_exit(t_game *game, char *str);
void	ft_free_matrix(char **mtx);
int		ft_end(t_game *game);
/* handleSprites.c */
void	ft_upload_sprites(t_game *game);
void	ft_unload_sprites(t_game *game);
/* initDDA.c */
void	ft_init_plyr(t_map *map, t_player *plyr);
void	ft_init_ray(t_player *plyr, t_ray *ray, int x);
void	ft_deltadist(t_ray *ray);
void	ft_step_sidedist(t_player *plyr, t_ray *ray);
void	ft_init_dda(t_game *game, int x);
/* initVars.c */
void	ft_init_vars(t_game *game);
void	ft_init_map_vars(t_game *game);
void	ft_init_plyr_vars(t_game *game);
void	ft_init_ray_vars(t_game *game);
void	ft_init_tex_vars(t_game *game);
/* initMap.c */
void	ft_init_map(t_game *game, t_map *map, char *fd_map);
char 	*get_next_line_del(int fd);
void	ft_read_map(t_game *game, int fd, int *count_all, int *count_map);
void	ft_check_chars(t_game *game, int fd, int count_all, int count_map);
void	ft_fill_map(t_map *map, char *fd_map, int count_a, int count_b);
/* initMLX.c */
int		ft_keys(int key, t_game *game);
void	ft_hooks(t_game *game);
void	ft_mlx_init(t_game *game);
void	ft_mlx_start(t_game *game);
/* loopMap.c */
void	ft_clear_img(t_game *game);
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

#endif
