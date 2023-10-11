/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcTime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:53:56 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/11 10:56:38 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_time(t_time *time)
{
	time->fps = 0;
	time->old_fps = 0;
}

void	ft_calc_time()
{
	time->old_fps = time->fps;
	time->fps = gettimeofday();
	time->frame_time = (time->fps - time->old_fps) / 1000.0;
	redraw();
	cls();
	time->move_speed = time->frame_time * 5.0;
	time->rot_speed = time->frame_time * 3.0;
}
