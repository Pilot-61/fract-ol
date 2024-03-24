/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 03:15:30 by mes-salh          #+#    #+#             */
/*   Updated: 2024/03/24 03:15:35 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractol(t_fractol *fractol)
{
    int	x;
    int	y;
    int	color;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            if (fractol->fractol == 1)
                color = mandelbrot(fractol, x, y);
            else if (fractol->fractol == 2)
                color = julia(fractol, x, y);
            my_mlx_pixel_put(&fractol->mlx, x, y, color);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractol->mlx.mlx, fractol->mlx.win, fractol->mlx.img, 0, 0);
}