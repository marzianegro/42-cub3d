/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeFree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:14:50 by marzianegro       #+#    #+#             */
/*   Updated: 2023/11/17 15:20:31 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free(void **item)
{
	if (*item)
	{
		free(*item);
		*item = NULL;
	}
}

void	ft_free_matrix(char **mtx)
{
	int	y;

	y = 0;
	if (mtx)
	{
		while (mtx[y])
		{
			ft_free((void **)&mtx[y]);
			y++;
		}
		free(mtx);
	}
}
