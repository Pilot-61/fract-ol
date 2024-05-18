/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mes_atof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 04:58:07 by mes-salh          #+#    #+#             */
/*   Updated: 2024/05/18 16:43:01 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	checker(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '-' || c[i] == '+')
		i++;
	while (c[i] && is_digit(c[i]))
		i++;
	if (c[i] == '.')
		i++;
	while (c[i] && is_digit(c[i]))
		i++;
	if (c[i] != '\0')
		return (1);
	return (0);
}

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
	while (is_digit(c[i]))
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
		while (is_digit(c[i]))
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
	if (checker(c))
		error("Error\nInvalid number\n");
	n = parse_integer(c, &i, &sign);
	d = parse_fraction(c, &i);
	return (sign * (n + d));
}
