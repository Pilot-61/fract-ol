/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 03:15:30 by mes-salh          #+#    #+#             */
/*   Updated: 2024/05/16 01:17:25 by mes-salh         ###   ########.fr       */
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

static void	set_complex(int x, int y, t_complex *c, t_fractol *fractol)
{
	c->r = ((double)x / WIDTH * 4.0 - 2.0) * fractol->zoom;
	c->i = -((double)y / HEIGHT * 4.0 - 2.0) * fractol->zoom;
}

static void	set_values(t_fractol *fractol, t_cordinate *cordinate,
	t_complex *c, t_complex *z)
{
	if (fractol->fractol == 1)
	{
		set_complex(cordinate->x, cordinate->y, c, fractol);
		z->r = 0.0;
		z->i = 0.0;
	}
	else if (fractol->fractol == 2)
	{
		c->r = fractol->x;
		c->i = fractol->y;
		set_complex(cordinate->x, cordinate->y, z, fractol);
	}
}

void	handle_pixel(t_fractol *fractol, t_cordinate *cordinate)
{
	t_complex	c;
	t_complex	z;
	int			i;

	set_values(fractol, cordinate, &c, &z);
	i = 0;
	while (i < fractol->max_iter)
	{
		z = complex_sum(complex_square(z), c);
		if ((z.r * z.r) + (z.i * z.i) > fractol->escape_value)
		{
			color_infinity(fractol, i);
			my_mlx_pixel_put(&fractol->mlx, cordinate->x,
				cordinate->y, fractol->color);
			return ;
		}
		i++;
		my_mlx_pixel_put(&fractol->mlx, cordinate->x, cordinate->y, BLACK);
	}
}

void	draw_fractol(t_fractol *fractol)
{
	t_cordinate	cordinate;

	cordinate.y = 0;
	while (cordinate.y < HEIGHT)
	{
		cordinate.x = 0;
		while (cordinate.x < WIDTH)
		{
			handle_pixel(fractol, &cordinate);
			cordinate.x++;
		}
		cordinate.y++;
	}
	mlx_put_image_to_window(fractol->mlx.mlx,
		fractol->mlx.win, fractol->mlx.img, 0, 0);
}
