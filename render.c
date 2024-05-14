/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 03:15:30 by mes-salh          #+#    #+#             */
/*   Updated: 2024/05/14 05:57:24 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	int	offset;

	offset = (y * mlx->line_len + x * (mlx->bpp / 8));
	*(unsigned int *)(mlx->addr + offset) = color;
}

void	handle_pixel(t_fractol *fractol, int x, int y)
{
	t_complex	c;
	t_complex	z;
	int			i;

	if (fractol->fractol == 1)
	{
		c.r = ((double)x / WIDTH * 4.0 - 2.0) * fractol->zoom;
		c.i = ((double)y / HEIGHT * 4.0 - 2.0) * fractol->zoom;
		z.r = 0.0;
		z.i = 0.0;
	}
	else if (fractol->fractol == 2)
	{
		c.r = fractol->x;
		c.i = fractol->y;
		z.r = ((double)x / WIDTH * 4.0 - 2.0) * fractol->zoom;
		z.i = ((double)y / HEIGHT * 4.0 - 2.0) * fractol->zoom;
	}
	i = 0;
	while (i < fractol->max_iter)
	{
		z = complex_sum(complex_square(z), c);
		if ((z.r * z.r) + (z.i * z.i) > fractol->escape_value)
		{
			color_divergence(fractol, i);
			my_mlx_pixel_put(&fractol->mlx, x, y, fractol->color);
			return ;
		}
		i++;
		my_mlx_pixel_put(&fractol->mlx, x, y, BLACK);
	}
}

void	draw_fractol(t_fractol *fractol)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(fractol, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx.mlx,
		fractol->mlx.win, fractol->mlx.img, 0, 0);
}
