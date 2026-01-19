/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrimpila <jrimpila@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:56:52 by jrimpila          #+#    #+#             */
/*   Updated: 2024/12/14 16:03:03 by jrimpila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_overflow(long long overflow, int positive, int last)
{
	if (overflow < LLONG_MIN / 10 || (last == 9 && overflow == LLONG_MIN / 10))
	{
		if (positive == 1)
			return (-1);
		else
			return (0);
	}
	return (2);
}

int	ft_atoi_spec(const char *nptr)
{
	int			positive;
	long long	rval;

	rval = 0;
	positive = 1;
	if (!(*nptr >= '0' && *nptr <= '9'))
	{
		ft_exit("Illegal number", NULL);
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (ft_check_overflow(rval, positive, *nptr) != 2)
			return (ft_check_overflow(rval, positive, *nptr));
		rval = rval * 10 - (*nptr - '0');
		nptr++;
	}
	if (*nptr == 0 || *nptr == '\n')
		return (rval * -1);
	else
		ft_exit("Illegal number", NULL);
	return (-1);
}
