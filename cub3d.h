/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:21:50 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/07 16:15:40 by mnegro           ###   ########.fr       */
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
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}			t_player;

typedef	struct s_vector
{
	/* data */
}			t_vector;

typedef	struct s_texture
{
	/* data */
}			t_texture;

typedef struct s_game
{
	t_map			map;
	void			*mlx_ptr;
	void			*win_ptr;
	t_player		plyr;
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
void	*ft_create(t_game *game, char *img);
void	ft_upload_all(t_game *game);
/* ft_loopMap.c */
int		ft_redrawinloop(t_game *game);
/* ft_termSprites.c */
void	ft_unload_all(t_game *game);

#endif
