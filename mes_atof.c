/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mes_atof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 04:58:07 by mes-salh          #+#    #+#             */
/*   Updated: 2024/05/14 04:58:36 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	parse_integer(char *c, int *index, int *sign)
{
	double	n;
	int		i;

	n = 0.0;
	i = *index;
	if (c[i] == '-')
	{
		*sign = -1;
		i++;
	}
	while (c[i] >= '0' && c[i] <= '9')
	{
		n = n * 10 + (c[i] - '0');
		i++;
	}
	*index = i;
	return (n);
}

static double	parse_fraction(char *c, int *index)
{
	double	d;
	int		i;
	double	decimalplace;

	d = 0.0;
	i = *index;
	decimalplace = 10;
	if (c[i] == '.')
	{
		i++;
		while (c[i] >= '0' && c[i] <= '9')
		{
			d = d + (c[i] - '0') / decimalplace;
			decimalplace *= 10;
			i++;
		}
	}
	*index = i;
	return (d);
}

double	mes_atof(char *c)
{
	double	n;
	double	d;
	int		i;
	int		sign;

	n = 0.0;
	d = 0.0;
	i = 0;
	sign = 1;
	n = parse_integer(c, &i, &sign);
	d = parse_fraction(c, &i);
	return (sign * (n + d));
}
