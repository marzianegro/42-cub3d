/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:15:51 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/10 12:50:10 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	The  atoi() function converts the initial portion of the string pointed to 
	by nptr to int.  The behavior is the same as strtol(nptr, NULL, 10); 
	except that atoi() does not detect errors.
	
	RETURN VALUE
	The converted value.
*/

#include "../libft.h"

int	ft_atoi(const char *nptr)
{
	int				i;
	long long int	res;
	int				sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	if (res * sign < INT_MIN || res * sign > INT_MAX)
		return (1);
	return (res * sign);
}
