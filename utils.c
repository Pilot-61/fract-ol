/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:54:14 by mes-salh          #+#    #+#             */
/*   Updated: 2024/05/13 23:54:10 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (ss1[i] && ss2[i] && (i < n - 1) && ss1[i] == ss2[i])
		i++;
	return (ss1[i] - ss2[i]);
}

t_complex	complex_sum(t_complex a, t_complex b)
{
	t_complex	c;

	c.r = a.r + b.r;
	c.i = a.i + b.i;
	return (c);
}

t_complex	complex_square(t_complex a)
{
	t_complex	c;

	c.r = (a.r * a.r) - (a.i * a.i);
	c.i = 2 * a.r * a.i;
	return (c);
}

double	ft_atof(char *c)
{
	double	n;
	double	d;
	int		i;
	int		sign;
	double	decimalplace;

	n = 0.0;
	d = 0.0;
	i = 0;
	sign = 1;
	if (c[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (c[i] >= '0' && c[i] <= '9')
	{
		n = n * 10 + (c[i] - '0');
		i++;
	}
	if (c[i] == '.')
	{
		i++;
		decimalplace = 10;
		while (c[i] >= '0' && c[i] <= '9')
		{
			d = d + (c[i] - '0') / decimalplace;
			decimalplace *= 10;
			i++;
		}
	}
	return (sign * (n + d));
}
